function RPS() {
    let computer = Math.random();
    let again = true

    while (again == true) {
        // User Pick
        const user = prompt("Enter Ur Hero (Rock, Paper or Scissor)");

        // Computer Pick
        if (computer <= 0.33) {
            computer = "Rock"
        } else if (computer >= 0.34 && computer <= 0.7) {
            computer = "Paper"
        } else {
            computer = "Scissor"
        }

        // Game Rule
        let result = ''
        if (user == computer) {
            result = 'Draw'
        } else if (user == "Rock") {
            result = (computer == "Paper") ? "Win" : "Lose"
        } else if (user == "Paper") {
            result = (computer == "Rock") ? "Win" : "Lose"
        } else {
            result = "Choose The Right One!"
        }

        // Result
        alert(`User pick ${user} and Computer pick ${computer}, ${result}`);

        again = confirm("Play Again?")
    }
    alert("Thanks for playing....")
}

RPS()