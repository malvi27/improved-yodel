import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class VowelCounter extends JFrame {
    private JTextField inputTextField;
    private JTextField outputTextField;
    private JButton countButton;
    private JButton resetButton;
    private JButton exitButton;

    VowelCounter() {
        createUI();
    }

    private void createUI() {
        // Set up the frame
        setTitle("Vowel Counter");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);

        // Input text field
        JLabel inputLabel = new JLabel("Enter a string:");
        inputLabel.setBounds(20, 20, 100, 30);
        add(inputLabel);

        inputTextField = new JTextField();
        inputTextField.setBounds(130, 20, 200, 30);
        add(inputTextField);

        // Output text field
        JLabel outputLabel = new JLabel("Vowel count:");
        outputLabel.setBounds(20, 60, 100, 30);
        add(outputLabel);

        outputTextField = new JTextField();
        outputTextField.setBounds(130, 60, 200, 30);
        outputTextField.setEditable(false);
        add(outputTextField);

        // Count button
        countButton = new JButton("Count Vowels");
        countButton.setBounds(20, 100, 120, 30);
        add(countButton);

        // Reset button
        resetButton = new JButton("Reset");
        resetButton.setBounds(150, 100, 80, 30);
        add(resetButton);

        // Exit button
        exitButton = new JButton("Exit");
        exitButton.setBounds(240, 100, 80, 30);
        add(exitButton);

        // Add action listeners
        countButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String inputText = inputTextField.getText();
                int vowelCount = countVowels(inputText);
                outputTextField.setText(String.valueOf(vowelCount));
            }
        });

        resetButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                inputTextField.setText("");
                outputTextField.setText("");
            }
        });

        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
    }

    private int countVowels(String input) {
        int count = 0;
        String vowels = "aeiouAEIOU";
        char[] chh=input.toCharArray();
        for (char c : chh) {
            if (vowels.indexOf(c) != -1) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new VowelCounter().setVisible(true);
            }
        });
    }
}