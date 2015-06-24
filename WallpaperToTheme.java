import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import java.io.File;
import java.awt.Color;
import java.io.IOException;

class WallpaperToTheme {
    public static void main(String[] args){
    
		BufferedImaged bi = new BufferedImaged();
		bi.do_job();

	}
}
class BufferedImaged {
		
		public void do_job(){
			BufferedImage image = null;
			try{
				image = ImageIO.read(new File("test.jpg"));
			} catch (IOException e) {
				p("error with reading file");
			}
			int w = image.getWidth();
			int h = image.getHeight();
			int i = 0;
		    int pixels = w*h;
			int[] dataBuffInt = image.getRGB(0,0,w,h,null,0,w);
			
		    RGB[] colours = new RGB[pixels];
		    Kmeans km = new Kmeans(colours, pixels);

		    for (i=0; i<pixels; i++){
				Color c = new Color(dataBuffInt[i]);
				colours[i] = new RGB(c.getRed(),c.getGreen(),c.getBlue());
		    }
		    p("Red\tGreen\tBlue");
		    for (i=0; i<pixels; i++){
		    	RGB rgb = colours[i];
		        p(rgb.getR() + "\t" + rgb.getG() + "\t" + rgb.getB());
		    }
        }
	

	private static void p(String s){
		System.out.println(s);
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


class Kmeans {
	
	RGB centroids[] = {new RGB(255,0,0),new RGB(0,255,0),new RGB(0,0,255)};//x2,y2,z2
	float distance = 255;//max distance
	float newDist = 0;
	int returnVal = 4;
	int[] closest = new int[pixels];
	RGB colours[] = new RGB[];
	int pixels = 0;

	public Kmeans(RGB colours[], pixels){
		this.colours = colours;
		this.pixels = pixels;
	}
	
	public void calcingDistances(){
		for (i=0; i<pixels; i++){
			RGB rgb = colours[i];
			closest[i] = km.calcDist(rgb);
	   	}
	   	
	}
	
	public static float calcDist(RGB rgb){
		float x1=rgb.getR();
		float y1=rgb.getG();
		float z1=rgb.getB();
		for(int i = 0; i < 3; i++){
			float x2 = centroids[i].getR();
			float y2 = centroids[i].getG();
			float z2 = centroids[i].getB();
			newDist = sqrt((x2-x1)^2+(y2-y1)^2+(z2-z1)^2);
			if(newDist < distance){
				distance = newDist;
				returnVal = i;
			}
		}
	}
	

}
