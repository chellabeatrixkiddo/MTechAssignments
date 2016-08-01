public class GCdemo {
    private class Blob {
        private int space[] = new int[10000];
        Blob initializeBlob() {
        	return (new Blob());
        }
    }
    public void finalize() {
    	System.out.println("Freeing the Blob");
    }
    public static void main(String[] args) {
        int n = 10000;
        Blob blobStore[] = new Blob[n];
        for(int i=0;i<n;i++) {
            Blob b = Blob.initializeBlob();
            blobStore[i] = b;
        }
        
    }
}