let canvas = document.getElementById('screen');
let ctx = canvas.getContext('2d'); 
console.log('hi');

const screenWidth = 800;
const screenHeight = 600;

let game = new Game(screenWidth, screenHeight);
new InputHandler(game, ctx);

let fpsInterval = 1000 / 15; // 15 FPS. 
let then = Date.now();

function gameLoop(timestamp) {	
	"use strict";

	let now = Date.now();
	let elapsed = now - then;

	// throttle fps at 15 for chunky feel
	if (elapsed > fpsInterval) {
		then = now - (elapsed % fpsInterval); // account for possible lag
		ctx.clearRect(0, 0, screenWidth, screenHeight);
		game.update();
		game.draw(ctx);

	}


	requestAnimationFrame(gameLoop);

}

requestAnimationFrame(gameLoop);


