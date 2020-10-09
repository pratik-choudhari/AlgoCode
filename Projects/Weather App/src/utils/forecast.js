const request = require('request');

const forecast = (longitude, latitude, callback) => {
    const url = 'http://api.weatherstack.com/current?access_key=29f9cf0e577a785e1dfb23a049e2336c&query='+ latitude + ',' + longitude;
    
    request({url, json: true}, (error, {body}/**Destructuring in place of response.body */) => {
         
        if(error){
            callback('Unable to connect to weather services!', undefined);
        } else if(body.error) {
           callback('Unable to find location', undefined)
        } else {
            callback(undefined, body.current.weather_descriptions[0] + '. It is currently ' + body.current.temperature + ' degrees outside but it feels like ' + body.current.feelslike + ' degrees. There is a ' + body.current.precip + '% chance of rain.', body.current.weather_icons[0]);
        }
    });
}

// exporting modules
module.exports = forecast;
