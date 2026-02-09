function greet(name) {
    if (!name)
        console.log(`Hi there!`);
    else
        console.log(`Hello ${name}`);
}
greet();
greet('Vaibhav');
greet();
greet('John');
greet('Chris');
pickComputerMove();
function pickComputerMove() {
    let computerMove = '';
    const randomNumber = Math.random();
    if (randomNumber >= 0 && randomNumber < 1 / 3) {
        computerMove = 'Rock';
    }
    else if (randomNumber >= 1 / 3 && randomNumber < 2 / 3) {
        computerMove = 'Paper';
    }
    else if (randomNumber >= 2 / 3 && randomNumber < 1) {
        computerMove = 'Scissors';
    }
    console.log(randomNumber);
    return computerMove;
}