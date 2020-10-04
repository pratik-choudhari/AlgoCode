const weatherForm = document.querySelector('form');
const search = document.querySelector('input');
const messageOne = document.querySelector('#message-1');
const messageTwo = document.querySelector('#message-2');
const output = document.querySelector('.output');

// messageOne.textContent = 'From JavaScript';

weatherForm.addEventListener('submit', (e) => {
     e.preventDefault();

     const location = search.value;
     
     output.style.display = 'block';
     messageOne.textContent = 'loading...';
     messageTwo.textContent = '';
     
     fetch('/weather?address='+encodeURIComponent(location)).then((response) => {
    response.json().then((data) => {
        messageOne.textContent = '';
        if(data.error){
            messageOne.textContent = data.error;
        } else {
            messageOne.textContent = data.location;
            messageTwo.textContent = data.forecastData;
            document.getElementById('wether-image').src = data.weatherImage;
        }
    })
})

})