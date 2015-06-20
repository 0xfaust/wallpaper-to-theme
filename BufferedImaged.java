import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import java.io.File;
import java.awt.Color;
import java.io.IOException;

public class BufferedImaged {
    public static void main(String[] args){
		BufferedImage image = null;
		try{
			image = ImageIO.read(new File("test.jpg"));
		} catch (IOException e) {
			System.out.println("error with reading file");
		}
		int w = image.getWidth();
		int h = image.getHeight();
		int i = 0;
        int pixels = w*h;
		int[] dataBuffInt = image.getRGB(0,0,w,h,null,0,w);

        RGB[] colours = new RGB[pixels];

        for (i=0; i<pixels; i++){
		    Color c = new Color(dataBuffInt[i]);
		    colours[i] = new RGB(c.getRed(),c.getGreen(),c.getBlue());
        }
        System.out.println("Red\tGreen\tBlue");
        for (i=0; i<pixels; i++){
        	RGB rgb = colours[i];
            System.out.println(rgb.getR() + "\t" + rgb.getG() + "\t" + rgb.getB());
        }
	}
}
class RGB {
    private int red;
    private int green;
    private int blue;
    
    public RGB(int red, int green, int blue) {
        this.red = red;
        this.green = green;
        this.blue = blue;
    }

    public int getR() { return red; }
    public int getG() { return green; }
    public int getB() { return blue; }
}
