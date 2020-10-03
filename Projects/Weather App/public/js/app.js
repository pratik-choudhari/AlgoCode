const weatherForm = document.querySelector('form');
const search = document.querySelector('input');
const messageOne = document.querySelector('#message-1');
const messageTwo = document.querySelector('#message-2');

// messageOne.textContent = 'From JavaScript';

weatherForm.addEventListener('submit', (e) => {
     e.preventDefault();

     const location = search.value;

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
        }
    })
})

})