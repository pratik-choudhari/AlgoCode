const express = require('express');
const path = require('path');
const quoteDisplay = require('./public/js/quote.js');
const hbs = require('hbs');

const app = express();
const port = 3000;

const publicDirectoryPath = path.join(__dirname,'./public');
const viewsPath = path.join(__dirname, './templates/views');

app.set('view engine', 'hbs');
app.set('views', viewsPath); 

app.use(express.static(publicDirectoryPath));

app.get('', async (req, res) => {
    try{
        const obj = await quoteDisplay();

        res.render('index', {
            quote: obj.text,
            author: obj.author
        })
    }
    catch(error)
    {
        res.send({
            error
        })
    }
    
})

app.listen(port, () => {
    console.log('Server is up and listening');
})

