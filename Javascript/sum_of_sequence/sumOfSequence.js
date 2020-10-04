const getSequence = (n) => {
    let seq = [];
    for (let i = 1; i <= n; i++) {
        seq.push(i * i - (i - 1) * (i - 1))
    }
    return { seqence: seq, sum: n * n }
}

console.log(getSequence(3));
console.log(getSequence(5));
console.log(getSequence(4));