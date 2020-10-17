class InputHandler {

	constructor(game, ctx) {
		document.addEventListener('keydown', (event) => {
			switch (event.keyCode) {
				case 37:
					game.snake.moveLeft();
					break;
				case 39: 
					game.snake.moveRight();
					break;
				case 38: 
					game.snake.moveUp();
					break;
				case 40:
					game.snake.moveDown();
					break;
				case 27:
					game.pauseGame(ctx);
					break;
				case 32: 
					game.startGame();
					break;
			}
		});


	}


}