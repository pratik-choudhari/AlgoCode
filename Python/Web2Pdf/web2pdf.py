import sys, getopt, pdfkit

def main(argv):
   try:
      website = argv[0]
   except getopt.GetoptError:
      print('python web2pdf.py <website url>')
      sys.exit(2)
   print("Converting:  " + website +  " to pdf..." )
   pdfkit.from_url(website, 'output.pdf')


if __name__ == "__main__":
   main(sys.argv[1:])
