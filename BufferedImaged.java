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
		
		int[] dataBuffInt = image.getRGB(0,0,w,h,null,0,w);
		
		Color c = new Color(dataBuffInt[0]);
		
		System.out.println("Red: "+c.getRed());
		System.out.println("Green: "+c.getGreen());
		System.out.println("Blue: "+c.getBlue());
		System.out.println("testing git pushing");
	}
}
