//Ip Validation using regex
function isValidIpv4Addr(ip) {
    //define regex
    let regex = /^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/
    //for eah ip address return true if it is valid IP address else return false
	for (let i = 0; i <= ip.length; i++) {
		if (regex.test(ip)) {
			return true;
        }
        return false;
    }
}

console.log(isValidIpv4Addr('000.12.12.034'));
console.log(isValidIpv4Addr('121.234.12.12'));
console.log(isValidIpv4Addr('23.45.12.56'));
console.log(isValidIpv4Addr('00.12.123.123123.123'));
console.log(isValidIpv4Addr('122.23'));
console.log(isValidIpv4Addr('Hello.IP'));