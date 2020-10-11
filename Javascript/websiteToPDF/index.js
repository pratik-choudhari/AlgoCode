const puppeteer = require('puppeteer');
const path = require('path');
const tldts = require('tldts');

const generatePDF = async () => {
  const url = process.argv[2];

  // Fetching domain name
  const domainName = tldts.getDomainWithoutSuffix(url);

  // Path for storing pdf files
  const pdfPath = path.join(__dirname, 'files', domainName + '.pdf');

  const browser = await puppeteer.launch();
  const page = await browser.newPage();
  await page.goto(url, {
    waitUntil: "networkidle2"
  });
  await page.setViewport({ width:1680, height: 1050});
  await page.pdf({
    path: pdfPath,
    format: "A4",
    printBackground: true,
    displayHeaderFooter: true,
    margin: {
      top: '38px' ,
      bottom: '38px',
      left: '38px',
      right: '38px'
    }
  })
  .then(() => {
    console.log("PDF downloaded at " + pdfPath);
  })

  await browser.close();
}

generatePDF();