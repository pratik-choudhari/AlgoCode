const request = require('request')

const geocode = (address, callback) => {
    const url = 'https://api.mapbox.com/geocoding/v5/mapbox.places/' + encodeURIComponent(address) + '.json?access_token=pk.eyJ1Ijoic2hpdmFtLXlhZGF2IiwiYSI6ImNrZXR2b2R6NjBqeGwycXA3NjM4OWsyODkifQ.xwyaAe_6icqfaTDHBhZDhw';

    request({ url, json: true }, (error, { body }/**Destructuring in place of response.body */) => {
        if (error) {
            callback('Unable to connect to location services!', undefined)
        } else if (body.features.length === 0) {
            callback('Unable to find location. Try another search.', undefined)
        } else {
            callback(undefined, {
                longitude: body.features[0].center[0],
                latitude: body.features[0].center[1],
                location: body.features[0].place_name
            })
        }
    })
}

module.exports = geocode;