class Enemy {
	constructor(screenWidth, screenHeight) {
		this.size = 20; 
		this.speed = this.size;
		this.currentSpeedx = this.speed;
		this.currentSpeedy = 0;
		this.screenWidth = screenWidth;
		this.screenHeight = screenHeight;
		this.x = 0;
		this.y = 0;
		this.sections = [{x: this.x, y: this.y}, {x: this.x, y: this.y}, {x: this.x, y: this.y}, this];
	}

	updateEnemy(snake) {
		let dx = snake.x - this.x;
		let dy = snake.y - this.y;

		// track position of the snake
		if (dx !== 0) {
			if (Math.sign(dx) === 1)  { // snake is right
				this.currentSpeedx = this.speed;
				this.currentSpeedy = 0;
			} else if (Math.sign(dx) === -1) { // snake is left
				this.currentSpeedx = -this.speed;
				this.currentSpeedy = 0;
			}

		}

		if (dy !== 0) {
			if (Math.sign(dy) === 1) { // snake is up
				this.currentSpeedy = this.speed;
				this.currentSpeedx = 0;
			} else if (Math.sign(dx) === -1) { // snake is down
				this.currentSpeedy = -this.speed; 
				this.currentSpeedx = 0;
			}
		}

		// move cpu
		this.x += this.currentSpeedx;
		this.y += this.currentSpeedy;

	}

	updateSections() {
		for (let i = 0; i < this.sections.length-1; i++) {
			this.sections[i].x = this.sections[i+1].x;
			this.sections[i].y = this.sections[i+1].y;
		}
	}

	drawSections(ctx) {
		for (let i = 0; i < this.sections.length-1; i++) {
			ctx.fillRect(this.sections[i].x, this.sections[i].y, this.size, this.size);
		}
	}

	drawEnemy(ctx) {
		ctx.fillRect(this.x, this.y, this.size, this.size);

	}

}









