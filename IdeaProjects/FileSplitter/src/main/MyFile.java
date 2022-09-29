package main;

import java.io.File;

public class MyFile extends File {
    private boolean split;
    private boolean zip;
    private int splitsize;

    public MyFile(String pathname) {
        super(pathname);
    }

    public boolean isSplit() {
        return split;
    }

    public void setSplit(final boolean split) {
        this.split = split;
    }

    public boolean isZip() {
        return zip;
    }

    public void setZip(final boolean zip) {
        this.zip = zip;
    }

    public int getSplitsize() {
        return splitsize;
    }

    public void setSplitsize(int splitsize) {
        this.splitsize = splitsize;
    }
}
