class Food {
	constructor(screenWidth, screenHeight, snake) {
		this.size = snake.size;
		this.generatePos();
	}

	generatePos() {
		this.position = {
			x: Math.floor(Math.random() * (screenWidth / this.size)) * this.size,
			y: Math.floor(Math.random() * (screenHeight / this.size)) * this.size,

		};
	}

	draw(ctx) {
		ctx.fillRect(this.position.x, this.position.y, this.size, this.size);

	}

}

