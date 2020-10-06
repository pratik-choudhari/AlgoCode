//find if given strings are anagram 

function findIfGivenStringsAreAnagrams(str1, str2) {
    //if strings are anagrams of each other return yes
	if (mainString(str1) === mainString(str2)){
        return "yes";
        //else return no
    } else {
        return "no";
    }
}

//main string function
function mainString(str) {
	return str.replace(/[^\w]/g, '').toLowerCase().split('').sort().join('');
}

console.log(findIfGivenStringsAreAnagrams("listen", "silent"));
console.log(findIfGivenStringsAreAnagrams("abcd", "abcdd"));