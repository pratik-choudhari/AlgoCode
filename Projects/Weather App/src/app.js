const path = require('path')
const express = require('express');
const hbs = require('hbs');
const geocode = require('./utils/geocode');
const forecast = require('./utils/forecast');

const app = express()
const port = process.env.PORT || 3000

// Define paths for Express config
const publicDirectoryPath = path.join(__dirname, '../public')
const viewsPath = path.join(__dirname, '../templates/views')
const partialsPath = path.join(__dirname, '../templates/partials')

// Setup handlebars engine and views location
app.set('view engine', 'hbs')
app.set('views', viewsPath)
hbs.registerPartials(partialsPath);

// Setup static directory to server
app.use(express.static(publicDirectoryPath))

app.get('', (req,res) => {
    res.render('index', {
        title: 'Weather',
        name: 'Shivam Yadav'  
    });
})

app.get('/about', (req,res) => {
    res.render('about', {
        title: 'About Project',
        name: 'Shivam'
    });
})

app.get('/help', (req,res) =>{
    res.render('help', {
        helpText: 'For any queries related to this project you can email me at shivam1272001@gmail.com.',
        title: 'Help',
        name: 'Shivam'
    })
})

app.get('/weather', (req,res) => {
    if(!req.query.address){
        return res.send({
            error: 'You must provide an address'
        })
    }
    const address = req.query.address;
    geocode(address, (error, {longitude, latitude, location} = {}) => {
        if(error){
            return res.send({
                error //shorthand syntax
            })
        }
        forecast(longitude,latitude, (error, forecastData, weatherImage) => {
            if(error){
                return res.send({
                    error
                })
            }
            res.send({
                address,
                location: location,
                forecastData: forecastData,
                weatherImage: weatherImage
            })
          })
    
    })
})

app.get('/help/*', (req,res) => {
    res.render('404',{
        title: '404',
        errorMessage: 'Help arcticle not found',
        name: 'Shivam'
    })
})

app.get('*', (req,res) => {
    res.render('404',{
        title: '404',
        errorMessage: 'Page not found',
        name: 'Shivam'
    })
})

app.listen(port, () => {
    console.log(`Server is up on port ${port}`);
})