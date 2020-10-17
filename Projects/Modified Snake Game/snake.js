class Snake {
	constructor(screenWidth, screenHeight) {
		this.size = 20; 
		this.speed = this.size;	
		this.currentSpeedx = this.speed;
		this.currentSpeedy = 0;
		this.screenWidth = screenWidth;
		this.screenHeight = screenHeight;
		this.x = screenWidth / 2;
		this.y = screenHeight / 2;
		this.sections = [this];
	}

	moveLeft() {
		if (this.currentSpeedx === 0) this.currentSpeedx = -this.speed;
		this.currentSpeedy = 0;
	}

	moveRight() {
		if (this.currentSpeedx === 0) this.currentSpeedx = this.speed;
		this.currentSpeedy = 0;
	}

	moveUp() {
		if (this.currentSpeedy === 0) this.currentSpeedy = -this.speed;
		this.currentSpeedx = 0;
	}

	moveDown() {
		if (this.currentSpeedy === 0) this.currentSpeedy = this.speed;
		this.currentSpeedx = 0;
	}

	updateSections() {
		for (let i=0; i<this.sections.length-1; i++) {
			this.sections[i].x = this.sections[i+1].x; 
			this.sections[i].y = this.sections[i+1].y;		
		}

	}

	drawSections(ctx) {
		for (let i=0; i<this.sections.length-1; i++) {
			ctx.fillRect(this.sections[i].x, this.sections[i].y, this.size, this.size);
		}
	}

	checkFood(food) {
		// add new section when snake eats food
		if (this.x === food.position.x && this.y === food.position.y) {
			this.sections.unshift({x: screenWidth / 2, y: screenHeight / 2}); 
			food.generatePos();
		} 

	}

	checkBorder() {
		// teleport snake to other side 
		if (this.x < 0) {
			this.x = 800;
		}

		if (this.x > 800) {
			this.x = -20;
		}

		if (this.y < -21) {
			this.y = 600;
		}
		if (this.y > 600) {
			this.y = -20;
		}
	}

	checkSelfCollision() {
		// kill snake if it runs into itself
		if (this.sections.length >= 3) {
			for (let i = this.sections.length-3; i > -1; i--) {
				if (this.x === this.sections[i].x && this.y === this.sections[i].y) {
					this.x = screenWidth / 2;
					this.y = screenHeight / 2;

					this.sections.splice(0, this.sections.length-1);
					console.log(this.sections.length);
					console.log('killed self');
					break;

				}
			}

		}

	}

	checkEnemy(enemy) {
		if ((enemy.sections[enemy.sections.length-1].x === this.x || enemy.sections[0].x === this.x) &&
			(enemy.sections[enemy.sections.length-1].y === this.y || enemy.sections[0].y === this.y)) {
			this.sections.splice(0, this.sections.length-1);
			console.log('killed self'); 

			this.x = screenWidth / 2;
			this.y = screenHeight / 2;

		}

	}

	update(food, enemy) {
		this.checkFood(food);
		this.checkBorder();
		this.checkSelfCollision();
		this.checkEnemy(enemy);

		// move head
		this.x += this.currentSpeedx;
		this.y += this.currentSpeedy;

	}

	draw(ctx) {
		ctx.fillRect(this.x, this.y, this.size, this.size);

	}

}
