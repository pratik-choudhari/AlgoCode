const weatherForm = document.querySelector('form');
const search = document.querySelector('input');
const messageOne = document.querySelector('#message-1');
const messageTwo = document.querySelector('#message-2');
const output = document.querySelector('.output');
const heart = document.getElementById('heart');
const main = document.getElementById('main');

class Store {
    static getArr(){
        let liked;
        if(localStorage.getItem('liked') == null){
            liked = [];
        }
        else{
            liked = JSON.parse(localStorage.getItem('liked'));
        }
        return liked;
    }

    static addArr(ele){
        const liked = Store.getArr();
        liked.push(ele);
        localStorage.setItem('liked', JSON.stringify(liked));
    }

    static delArr(index){
        const liked = Store.getArr();
        liked.splice(index, 1);
        localStorage.setItem('liked', JSON.stringify(liked));
    }
}

function init(){
    const liked = Store.getArr();
    liked.forEach((name) => newItem(name));
}

function newItem(location){
    
    fetch('/weather?address='+encodeURIComponent(location)).then((response) => {
   response.json().then((data) => {
       if(data.error){
           var newChild = `<div><p>${data.error}</p></div>`;
           output.insertAdjacentHTML('afterend',newChild);
       } else {
           var newChild = `<div class="liked">
           <div class="head">
              <img id="wether-image" src="${data.weatherImage}" alt="" srcset="">
              <i class="fas fa-heart" id="heart"></i>
           </div>
           <hr>
           <div>
              <p>${data.location}</p>
              <p>${data.forecastData}</p>
           </div>
       </div>`;
       output.insertAdjacentHTML('afterend',newChild);
       }
   })
})

}

function isLiked(location){
    const likedArr = Store.getArr();
    for(var i=0;i<likedArr.length;i++){
        if(location == likedArr[i])
           return true;
    }
    return false;
}

function indexOf(location){
    const likedArr = Store.getArr();
    for(var i=0;i<likedArr.length;i++){
        if(location == likedArr[i])
           return i;
    }
}

main.addEventListener('click', (e) => {
       const location = e.target.parentNode.parentNode.children[2].children[0].textContent;
       var arr = location.split(',');
       const placeName = arr[0];
       if(e.target.classList.contains('fas')){
           // delete item from array
          var index = indexOf(placeName);
          Store.delArr(index);
          e.target.parentElement.parentElement.remove();
       }
       else if((placeName != "") && !isLiked(placeName)){
            Store.addArr(placeName);
            output.style.display = "none";
            newItem(placeName);
           }
        else if(e.target.classList.contains('fa-heart')){
            alert('It is already liked!');
        }
});


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