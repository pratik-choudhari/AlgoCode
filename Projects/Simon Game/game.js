alert("test");         
var buttons = ["green","red","yellow","blue"];
var gameseq = [];
var userseq = [];
var started = false;
var flag=0;
var l=0;

$(document).on("keypress",function(){
    if(!started){
    // alert("Inside keypress");
    NextSeq();
    $("#level-title").text("Level "+l);
    started=true;
    }   
})

$(".btn").on("click",function(){
    // blink(i);
    var i = $(this).attr("id");
    
    $("#"+i).addClass("pressed");
    
    setTimeout(function(){$("#"+i).removeClass("pressed");},100);
    
    userseq.push(i);
    sound(i);
    $("#"+i).fadeIn(100).fadeOut(100).fadeIn(100);
    
    check(userseq.length-1);
});

function NextSeq(){
    var randnum = Math.floor(Math.random()*4);
    gameseq.push(buttons[randnum]);
    userseq=[]
    l++;
    $("#level-title").text("Level "+l);
     $("#"+buttons[randnum]).fadeIn(100).fadeOut(100).fadeIn(100);
     sound(buttons[randnum]);
    // display();
}

function display(){
    for(var i=0;i<gameseq.length;i++)
    {
        $("#" + gameseq[i]).fadeIn(100).fadeOut(100).fadeIn(100);
        sound(gameseq[i]);
    }
}
function sound(b){
    var audio = new Audio("sounds/" + b + ".mp3");
    audio.play();
}

function check(currentLevel){
    if (userseq[currentLevel] === gameseq[currentLevel]) {
        if (userseq.length === gameseq.length){
            // alert("hell");
          setTimeout(function () {
            NextSeq();
          }, 1000);
        }
      } 
    else {
        // alert("hell");
        sound("wrong");
        $("body").addClass("game-over");
        $("#level-title").text("Game Over, Press Any Key to Restart");
  
        setTimeout(function () {
          $("body").removeClass("game-over");
        }, 200);
  
        startOver();
    }

    function startOver() {
        l= 0;
        gameseq = [];
        started = false;
      }
}
        // display();
        // userseq=[];
        // for(var i=0;i<userseq.length;i++)
        // {
        //     $("button").addEventListener("click",function(){});
        //     if(userseq[i]===gameseq[i])
        //         continue;
        //     else
        //     {
        //         var audio = new Audio("sounds/wrong.mp3");
        //         audio.play();
        //         flag=1;
        //         break;
        //     }
        // }
        // if(flag===1)
        // {
        //     l=0;
        //     gameseq=[];
        // }
        // else{
        //     NextSeq();
        // }
        // l++;  
