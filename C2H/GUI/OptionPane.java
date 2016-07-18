package GUI;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GraphicsEnvironment;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Properties;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JComboBox;
import javax.swing.JFileChooser;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.filechooser.FileSystemView;

public class OptionPane extends JPanel {
	public FileSystemView fileSystemView =
	        FileSystemView.getFileSystemView();
	
	private Properties propertie;
    private FileInputStream inputFile;
    private FileOutputStream outputFile;
	
	GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
	String fonts[] = ge.getAvailableFontFamilyNames();
	
	JTextField jtfConverTo = new JTextField();
	
	Color[] colors = new Color[4];
	
	JComboBox jcbSourceCode = new JComboBox(new String[]{"Java", "C", "C++", "JavaScript"});
	
	JComboBox jcbType = new JComboBox(new String[]{"�ؼ���", "ע��", "ֱ����", "����"});
	
	JComboBox jcbFont = new JComboBox(fonts);
	
	JComboBox jcbFontSize = new JComboBox(
			new String[]{"xx-small","x-small", "small", "medium", 
						"large", "x-large", "xx-large"});
	
	JButton jbtDefault = new JButton("Ĭ��");
	
	JButton jbtConvert = new JButton("��ʼת��");
	
	public OptionPane() {
		try {
			setDefaultOption();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		Properties p = new Properties();
		
		try {
			inputFile = new FileInputStream("config/option.properties");
		} catch (FileNotFoundException e2) {
			// TODO Auto-generated catch block
			e2.printStackTrace();
		}
		
		try {
			p.load(inputFile);
			inputFile.close();
		} catch (IOException e2) {
			// TODO Auto-generated catch block
			e2.printStackTrace();
		}
		
		jcbSourceCode.setSelectedItem(p.getProperty("sourceCode"));
		jcbFont.setSelectedItem(p.getProperty("fontType"));
		jcbFontSize.setSelectedItem(p.getProperty("fontSize"));
		
		JPanel jp = new JPanel(new BorderLayout());
		JPanel jp1 = new JPanel(new GridLayout(5, 1, 10, 20));
		JPanel jp2 = new JPanel(new GridLayout(5, 1, 10, 20));
		
		JLabel sourceCode = new JLabel("Դ�룺");
		JLabel color = new JLabel("��ɫ��");
		JLabel font = new JLabel("���壺");
		JLabel fontSize = new JLabel("�����С��");
		JLabel convertTo = new JLabel("ת������");
		jp1.add(sourceCode);
		jp1.add(color);
		jp1.add(font);
		jp1.add(fontSize);
		jp1.add(convertTo);
		
		JPanel jp3 = new JPanel(new GridLayout(1, 2, 5, 0));
		jcbSourceCode.setToolTipText("֧�ֵ�Դ�ļ����ԣ��ɲ�ѡ�񣬳�����Զ�ƥ������");
		jcbType.setToolTipText("���ݲ�ͬ�﷨ѡ���Ӧ��ɫ");
		
		JButton jbtColor = new JButton();
		JLabel jlbColor = new JLabel("       ");
		jlbColor.setOpaque(true);
		jbtColor.add(jlbColor);
		
		for (int i = 0; i < colors.length; i++) {
			String[] rgb = p.getProperty("color" + i).split(" ");
			int red = Integer.parseInt(rgb[0]);
			int green = Integer.parseInt(rgb[1]);
			int blue = Integer.parseInt(rgb[2]);
			colors[i] = new Color(red, green, blue);
		}
		
		jlbColor.setBackground(colors[0]);
		
		JColorChooser jcc = new JColorChooser();
		jp3.add(jcbType);
		jp3.add(jbtColor);
		
		
		
		jtfConverTo.setText(fileSystemView.getRoots()[0].getAbsolutePath() + "     ");
		jtfConverTo.setToolTipText("Ĭ�ϵ�ǰ�ļ���");
		JButton jbtPath = new JButton("-");
		jbtPath.setToolTipText("ѡ���ļ���");
		jbtPath.setBounds(130, 2, 25, 20);
		jtfConverTo.add(jbtPath);
		JButton jbtConverTo = new JButton();
		jtfConverTo.add(jbtConverTo);
		jp2.add(jcbSourceCode);
		jp2.add(jp3);
		jp2.add(jcbFont);
		jp2.add(jcbFontSize);
		jp2.add(jtfConverTo);
		
		JPanel jp4 = new JPanel(new FlowLayout(FlowLayout.CENTER, 5, 20));
		JButton jbtSave = new JButton("����");
		jbtSave.setToolTipText("���浱ǰ����");
		jbtDefault.setToolTipText("��ԭĬ������");
		jbtConvert.setToolTipText("��ѡ����ļ�����ת��");
		jp4.add(jbtSave);
		jp4.add(jbtDefault);
		jp4.add(jbtConvert);
		

		jp.add(jp1, BorderLayout.WEST);
		jp.add(jp2);
		
		jcbType.addItemListener(new ItemListener() {
			
			@Override
			public void itemStateChanged(ItemEvent e) {
				// TODO Auto-generated method stub
				jlbColor.setBackground(colors[jcbType.getSelectedIndex()]);
			}
		});
		jbtColor.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				int index = jcbType.getSelectedIndex();
				Color temp = JColorChooser.showDialog(jlbColor, "��ɫ", colors[index]);
				if (temp != null) {
					colors[index] = temp;
					
					jlbColor.setBackground(colors[index]);
				}
				
			}
		});
		jbtPath.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				JFileChooser jfc = new JFileChooser();
				jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY );
				jfc.setCurrentDirectory(new File(jtfConverTo.getText().split(" ")[0]));
				jfc.showSaveDialog(jtfConverTo);
				if (jfc.getSelectedFile() != null) {
					jtfConverTo.setText(jfc.getSelectedFile().getAbsolutePath() + "     ");
				}
			}
		});
		jbtDefault.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				colors[0] = new Color(0, 102, 153);
				colors[1] = new Color(0, 130, 130);
				colors[2] = Color.blue;
				colors[3] = Color.black;
				jcbFont.setSelectedItem("Consolas");
				jcbFontSize.setSelectedIndex(2);
				jlbColor.setBackground(colors[jcbType.getSelectedIndex()]);
			}
		});
		
		jbtSave.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				try {
					saveNewOption();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		});
		
		
		
		setLayout(new BorderLayout());
		add(jp, BorderLayout.NORTH);
		add(jp4);
		
		setBorder(BorderFactory.createTitledBorder("����"));
		setPreferredSize(new Dimension(230, 0));
		
		
	}
	
	public JTextField getJtfConverTo() {
		return jtfConverTo;
	}
	
	public JButton getJbtDefault() {
		return jbtDefault;
	}
	
	public JButton getJbtConvert() {
		return jbtConvert;
	}
	
	public Color[] getColors() {
		return colors;
	}
	
	public String getFontType() {
		return (String)jcbFont.getSelectedItem();
	}
	
	public String getFontSize() {
		return (String)jcbFontSize.getSelectedItem();
	}
	
	public JComboBox getJcbSourceCode() {
		return jcbSourceCode;
	}
	
	public void setDefaultOption() throws IOException {
		if (!(new File("config/option.properties").exists())) {
			Properties p = new Properties();
			
			p.setProperty("sourceCode", "Java");
			p.setProperty("color0", "0 102 153");
			p.setProperty("color1", "0 130 130");
			p.setProperty("color2", "0 0 255");
			p.setProperty("color3", "0 0 0");
			p.setProperty("fontType", "Consolas");
			p.setProperty("fontSize", "small");
			
			outputFile = new FileOutputStream("config/option.properties");
			p.store(outputFile, "option.properties");
			outputFile.close();
		}
	}
	
	public void saveNewOption() throws IOException {
		Properties p = new Properties();
		
		inputFile = new FileInputStream("config/option.properties");
		p.load(inputFile);
		inputFile.close();
		
		p.setProperty("sourceCode", jcbSourceCode.getSelectedItem().toString());
		p.setProperty("color0", colors[0].getRed() + " " +
				colors[0].getGreen() + " " + colors[0].getBlue());
		p.setProperty("color1", colors[1].getRed() + " " +
				colors[1].getGreen() + " " + colors[1].getBlue());
		p.setProperty("color2", colors[2].getRed() + " " +
				colors[2].getGreen() + " " + colors[2].getBlue());
		p.setProperty("color3", colors[3].getRed() + " " +
				colors[3].getGreen() + " " + colors[3].getBlue());
		p.setProperty("fontType", jcbFont.getSelectedItem().toString());
		p.setProperty("fontSize", jcbFontSize.getSelectedItem().toString());
		
		outputFile = new FileOutputStream("config/option.properties");
		p.store(outputFile, "option.properties");
		outputFile.close();
	}
}
