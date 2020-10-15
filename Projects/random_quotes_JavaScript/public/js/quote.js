const axios = require('axios');
const { JSDOM } = require('jsdom');

async function quoteDisplay(){
    try{
        // Generating a random page no. between 1 to 10 
        const page = Math.round(Math.random()*10 + 1);
        const data = await axios.get(`http://quotes.toscrape.com/page/${page}/`);

        // Fetching data from jsdom
        const { document } = new JSDOM(data.data).window;
        const quotesNodeList = document.querySelectorAll('.quote');
        const quotes = Array.prototype.slice.call(quotesNodeList);

        const quoteNumber = Math.round(Math.random()*10 + 1);
        const text = quotes[quoteNumber].querySelector('.text').textContent;
        const author = quotes[quoteNumber].querySelector('.author').textContent;
        return {
            text,
            author
        };
    }
    catch(error){
        console.log("Error: " + error);
    }
}

module.exports = quoteDisplay;