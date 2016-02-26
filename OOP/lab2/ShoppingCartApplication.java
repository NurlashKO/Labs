import  java.io.*;
import  java.util.*;



/* DOCUMENT THIS CLASS */
public class ShoppingCartApplication  {

	private static BufferedReader  stdIn =
		new  BufferedReader(new  InputStreamReader(System.in));
	private static PrintWriter  stdOut =
		new  PrintWriter(System.out, true);
	private static PrintWriter  stdErr =
		new  PrintWriter(System.err, true);

	private ShoppingCart cart;

	/* DOCUMENT THIS PUBLIC METHOD */
	public static void main(String[]  args) throws IOException  {

		ShoppingCartApplication application = new  ShoppingCartApplication();

		application.run();
	}

	private void run() throws IOException  {

		cart = new  ShoppingCart();

		int  choice = getChoice();

		while (choice != 0)  {

			if (choice == 1)  {
				cart.addProduct(readProduct());
			} else if (choice == 2)  {
				stdOut.println(cart.toString());
			} else if (choice == 3)  {
				stdOut.println(cart.getTotalValue());
			}

			choice = getChoice();
		}
	}

	private int  getChoice() throws IOException  {

		do  {

			int input;

			try  {
				stdErr.println();
				stdErr.print("[0]  Quit\n"
				             + "[1]  Add Product\n"
				             + "[2]  Display Products\n"
				             + "[3]  Display Total\n"
				             + "choice>");
				stdErr.flush();

				input = Integer.parseInt(stdIn.readLine());

				if (0 <= input && 3 >= input)  {

					return  input;

				} else {
					stdErr.println("Invalid choice:  " + input);
				}
			} catch (NumberFormatException  nfe)  {
				stdErr.println(nfe);
			}
		}  while (true);
	}

	private Product readProduct() throws IOException {

		final String DELIM = "_";

		String name = "";
		int quantity = 0;
		double price = 0.0;


		/* PLACE YOUR CODE HERE */
        do
        {
            try {
                System.out.print("Product_quantity_price > ");
		        String data[] = stdIn.readLine().split(DELIM);
                System.out.println("");

                if (data.length != 3) throw new NumberFormatException();

                name = data[0];
		        quantity = Integer.parseInt(data[1]);
		        price = Double.parseDouble(data[2]);
                if (quantity <= 0 || price <= 0) throw new NumberFormatException();
                return new Product(name, quantity, price);
            } catch (NumberFormatException nfe){
                stdErr.println("invalid input");
            }
        } while (true);

	}
}
