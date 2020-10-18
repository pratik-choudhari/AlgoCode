const GAMESTATE = {
	PAUSED: 0,
	RUNNING: 1,
	MENU: 2,
	GAMEOVER: 3,
};

class Game {
	constructor(gameWidth, gameHeight) {
		this.gameWidth = gameWidth;
		this.gameHeight = gameHeight;
		this.snake = new Snake(gameWidth, gameHeight);
		this.enemy = new Enemy(gameWidth, gameHeight);
		this.food = new Food(gameWidth, gameHeight, this.snake);
		this.gamestate = GAMESTATE.MENU;


	}

	update() { 
		/* NOTE: updates and draws snake sections together to prevent
		the black box glitch in the middle of screen from happening */

		if (this.gamestate === GAMESTATE.PAUSED || 
			this.gamestate === GAMESTATE.MENU ||
			this.gamestate === GAMESTATE.GAMEOVER) 
			return;

		// update sub-sections of snake and sections
		ctx.fillStyle = 'black';
		this.snake.updateSections();
		this.snake.drawSections(ctx);
	
		// update sections of enemy and head
		this.enemy.updateSections();
		this.enemy.updateEnemy(this.snake);
		
	}

	draw(ctx) {
		/* NOTE: updates and draws snake sections together to prevent
		the black box glitch in the middle of screen from happening */
		// draw sub-sections of snake and sections

		if (this.gamestate == GAMESTATE.PAUSED) {
			ctx.rect(0, 0, this.gameWidth, this.gameHeight);
			ctx.fillStyle = 'RGBA(0, 0, 0, 0.5)'; 
			ctx.fill(); 

			ctx.font = "30px Arial";
			ctx.fillStyle = 'white';
			ctx.textAlign = 'center'; 
			ctx.fillText('Paused', this.gameWidth / 2, this.gameHeight / 2);

			ctx.fillStyle = 'red';
			this.enemy.drawSections(ctx);		
			this.enemy.drawEnemy(ctx);

			ctx.fillStyle = 'black';
			this.snake.draw(ctx);
			this.snake.drawSections(ctx);

			ctx.fillStyle = 'green';
			this.food.draw(ctx);


		} else if (this.gamestate == GAMESTATE.MENU) {
			ctx.rect(0, 0, this.gameWidth, this.gameHeight);
			ctx.fillStyle = 'RGBA(0, 0, 0, 1)'; 
			ctx.fill(); 

			ctx.font = "30px Arial";
			ctx.fillStyle = 'white';
			ctx.textAlign = 'center'; 
			ctx.fillText('Press SPACEBAR To Start', this.gameWidth / 2, this.gameHeight / 2);
			ctx.fillStyle = 'black';

		} else if (this.gamestate == GAMESTATE.GAMEOVER) {

			ctx.rect(0, 0, this.gameWidth, this.gameHeight);
			ctx.fillStyle = 'RGBA(0, 0, 0, 1)'; 
			ctx.fill(); 


			ctx.font = "30px Arial";
			ctx.fillStyle = 'white';
			ctx.textAlign = 'center'; 
			ctx.fillText('GAME OVER', this.gameWidth / 2, this.gameHeight / 2);
			ctx.fillStyle = 'black';

		} else {
			ctx.fillStyle = 'black';

			this.snake.update(this.food, this.enemy);
			this.snake.draw(ctx);
			
			// draw sections of enemy and head
			ctx.fillStyle = 'red';
			this.enemy.drawSections(ctx);		
			this.enemy.drawEnemy(ctx);
			// draw food
			ctx.fillStyle = 'green';
			this.food.draw(ctx);


		}

		
	}

	startGame() {
		this.gamestate = GAMESTATE.RUNNING;
	}

	pauseGame(ctx) {
		if (this.gamestate == GAMESTATE.PAUSED) { // unpause game if paused
			this.gamestate = GAMESTATE.RUNNING;
			ctx.fillStyle = 'black';
		} else {
			this.gamestate = GAMESTATE.PAUSED // pause game if unpaused
		}
	}

}








