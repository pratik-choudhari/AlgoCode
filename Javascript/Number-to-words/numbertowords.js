const a = ['', 'One ', 'Two ', 'Three ', 'Four ', 'Five ', 'Six ', 'Seven ', 'Eight ', 'Nine ', 'Ten ', 'Eleven ', 'Twelve ', 'Thirteen ', 'Fourteen ', 'Fifteen ', 'Sixteen ', 'Seventeen ', 'Eighteen ', 'Nineteen ']
const b = ['', '', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']

const regex = /^(\d{2})(\d{2})(\d{2})(\d{1})(\d{2})$/

const getLT20 = (n) => a[Number(n)]
const get20Plus = (n) => b[n[0]] + ' ' + a[n[1]]

function numWords (input) {
  const num = Number(input)
  if (isNaN(num)) return ''
  if (num === 0) return 'Zero'

  const numStr = num.toString()
  if (numStr.length > 9) {
    throw new Error('overflow') // Does not support converting more than 9 digits yet
  }

  const [, n1, n2, n3, n4, n5] = ('000000000' + numStr).substr(-9).match(regex) // left pad zeros

  let str = ''
  str += n1 != 0 ? (getLT20(n1) || get20Plus(n1)) + 'Crore ' : ''
  str += n2 != 0 ? (getLT20(n2) || get20Plus(n2)) + 'Lakh ' : ''
  str += n3 != 0 ? (getLT20(n3) || get20Plus(n3)) + 'Thousand ' : ''
  str += n4 != 0 ? getLT20(n4) + 'Hundred ' : ''
  str += n5 != 0 && str != '' ? 'and ' : ''
  str += n5 != 0 ? (getLT20(n5) || get20Plus(n5)) : ''

  return str.trim()
}
const prompt = require("prompt-sync")();

const inputasstr = prompt("Please enter the Number you want to convert");

const inputasnum = Number(inputasstr);

const res = numWords(inputasnum);
console.log(res);
