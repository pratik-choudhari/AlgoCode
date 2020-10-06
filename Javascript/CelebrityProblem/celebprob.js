function FindCeleb (matrix) {
    function HaveAcquaintance(A, B) {
        return matrix[A][B] == 1
    }

    // Initial candidate 
    cand = 0

    // Check for best candidate.
    // If candidate knows "i" then candidate can't be a celebrity, 
    // but "i" could be a celebrity, so "i" becomes candidate
    for (var i = 1; i < matrix.length; i++) {
        if(HaveAcquaintance(cand, i)){
            cand = i
        }
    }

    // Verify candidate is the celebrity
    for(var i = 0; i < matrix.length; i++)
    {
        if(i != cand && (HaveAcquaintance(cand, i) || !HaveAcquaintance(i, cand))){
            cand = -1
            break
        }
    }
}

var MATRIX = [ 
    [0, 0, 1, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 0],
    [0, 0, 1, 0] ]

celeb = FindCeleb(MATRIX);
if(celeb == -1) {
    console.log("No celebrity")
} else {
    console.log(`id = ${cand}`)
}