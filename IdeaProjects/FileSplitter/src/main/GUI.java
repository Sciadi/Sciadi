package main;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import java.awt.event.ComponentAdapter;
import java.awt.event.ContainerAdapter;
import java.io.File;

import static java.sql.Types.NULL;


public class GUI extends JFrame {

    private JButton selectButton;
    private JCheckBox splitCheckBox;
    private JCheckBox zipCheckBox;
    private JButton nextButton;
    private JList<String> list1;
    private DefaultListModel<String> DFM;
    private DefaultListModel<MyFile> DFM2;
    private JList<MyFile> list2;
    private JButton startButton;
    private JButton resetButton;
    private JComboBox<Integer> comboBox;
    private JButton deleteButton;
    private JPanel mainPanel;

    private static final Integer[] dim={64,128,256,512};

    public GUI(){
        super("Splitter");
        initStuff();
        setMainFrame();
        setListeners();
    }

    private void initStuff() {
        list1.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if(splitCheckBox.isSelected() | zipCheckBox.isSelected()){
                    nextButton.setEnabled(true);
                }
                else{
                    nextButton.setEnabled(false);
                }
            }
        });
        DFM = new DefaultListModel<>();
        DFM2 = new DefaultListModel<>();
    }

    private void setListeners() {
        /**
         *   Sets MYFILE info from checkbox & combobox
         */
        nextButton.addActionListener(e -> {
            String path = list1.getSelectedValue();
            int idx = list1.getSelectedIndex();

            MyFile MF = new MyFile(path);
            getData(MF);
            DFM2.addElement(MF); //moves path from list1 to list2
            DFM.removeElementAt(idx);
            list2.setModel(DFM2);

        });

        resetButton.addActionListener(e -> {
            dispose();
            new GUI();
        });

        selectButton.addActionListener(e -> {
            JFileChooser fc = new JFileChooser();
            fc.setMultiSelectionEnabled(true);
            int ret = fc.showOpenDialog(null);
            File []files = fc.getSelectedFiles();

            if (ret == JFileChooser.APPROVE_OPTION){
               for(File f: files){
                   DFM.addElement(f.getAbsolutePath());
               }
                list1.setModel(DFM);
            }
        });
    }

    private void setMainFrame() {
        //this.comboBox = new JComboBox<Integer>();
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        this.setContentPane(mainPanel);
        this.setSize(800,700);
        this.setVisible(true);
        /**
         *  Set JComboBox values
         */
        for (int a: dim) {
            comboBox.addItem(a);
        }
    }

    /**
     * HELPER
     * @param list of file
     * @return String arrays with path
     */
    private String[] filetoString(File[] list){
        String [] ret = new String[list.length];
        int i=0;
        for (File f: list) {
            ret[i] = f.getAbsolutePath();
            i++;
        }
        return ret;
    }

    public void getData(MyFile data) {
        data.setSplit(splitCheckBox.isSelected());
        data.setZip(zipCheckBox.isSelected());
        data.setSplitsize((Integer) comboBox.getSelectedItem());
    }

}
