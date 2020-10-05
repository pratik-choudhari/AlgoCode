import java.util.Scanner;

public class IPRegex {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuffer ans = new StringBuffer();
		int numInput;
		boolean isIP = true;

		numInput = sc.nextInt();
		sc.nextLine();

		for (int i = 0; i < numInput; i++) {
			String ipNum = sc.nextLine().strip();

			String[] ipNumComponents = ipNum.split("\\.");

			if (ipNumComponents.length != 4) {
				isIP = false;
			}
			else { 
				for (int n = 0; n < 4; n++) {
					try {
						int currVal = Integer.parseInt(ipNumComponents[n]);

						if (currVal > 255 && currVal < 0) {
							isIP = false;
						}
					} catch (NumberFormatException e) {
						isIP = false;
					}
				}
			}

			ans.append((isIP) ? "true\n" : "false\n");
		}
		
		System.out.println(ans);
		
		sc.close();
	}
}
