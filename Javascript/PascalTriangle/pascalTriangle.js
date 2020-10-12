const readline = require('readline');
let numRows;

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question("Enter the number of rows of the Pascal's Triangle: ", answer => {
  numRows = answer;

  const generateTriangle = numRows => {
    let pascalTriangle = new Array(numRows);

    for (let i = 0; i < numRows; i++) {
      const row = new Array(i + 1);

      // In each row we know the first and last number are both 1
      row[0] = 1;
      row[row.length - 1] = 1;

      // Then we fill the rest of the row, doing the summations of the previous row
      for (let j = 1; j < row.length - 1; j++) {
        let rowAbove = pascalTriangle[i - 1];
        row[j] = rowAbove[j] + rowAbove[j - 1];
      }

      pascalTriangle[i] = row;
      // Finally we print each row
      console.log(pascalTriangle[i]);
    }
    return pascalTriangle;
  };
  generateTriangle(numRows);
  rl.close();
});
