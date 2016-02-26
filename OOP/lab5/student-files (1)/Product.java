public class Product
{
    private String code, description;
    private double price;

    public Product(String initialCode,
            String initialDescription,
            double initialPrice)
    {
        code = initialCode;
        description = initialDescription;
        price = initialPrice;
    }

    public String getCode()
    {
        return code;
    }
    public String getDescription()
    {
        return description;
    }
    public double getPrice()
    {
        return price;
    }
    public boolean equals(Object object)
    {
        if (object instanceof Product)
            return code == (((Product)object).getCode());
        return false;
    }

    public String toString()
    {
        return code.toString() + "_" + description.toString() + "_" + String.valueOf(price);
    }
}
