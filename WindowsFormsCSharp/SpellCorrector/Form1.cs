using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class MainForm : Form
    {
        Words words;
        bool skipFixing;
        public MainForm()
        {
            InitializeComponent();
            words = new Words(new LevenshteinDistanceKeySimilarity());
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
            if (skipFixing) return;
            RichTextBox richTextBox = (RichTextBox)sender;
            string text = richTextBox.Text;
            int cursorIndex = richTextBox.SelectionStart;
            if (cursorIndex < 2 || !Formatter.isDelimiter(text[cursorIndex - 1])) return;
            
                int pos = cursorIndex - 2, len = 0;
                while (pos >= 0 && !Formatter.isDelimiter(text[pos]))
                {
                    pos--;
                    len++;
                }
                pos++;
                string lastWord = text.Substring(pos, len);
                if (lastWord == "" || words.contains(lastWord)) return;
                
                if (autoFixing.Checked)
                {
                    string word = words.getSimilar(lastWord, 1).First();
                    skipFixing = true;
                    richTextBox.Text = Formatter.replaceWord(text, word, pos, len);
                    skipFixing = false;
                }
                else 
                {
                    replaceSuggestionList.Items.Clear();
                    foreach (string word in words.getSimilar(lastWord, 5))
                    {
                        replaceSuggestionList.Items.Add(new ReplaceSuggestionString(word, pos, len));
                    }
                }
                
            
            

            richTextBox1.Select(richTextBox1.Text.Length, 0);
        }

        private void replaceSuggestionList_DoubleClick(object sender, EventArgs e)
        {
            int index = this.replaceSuggestionList.IndexFromPoint(((MouseEventArgs)e).Location);
            if (index != System.Windows.Forms.ListBox.NoMatches)
            {
                string text = richTextBox1.Text;
                ReplaceSuggestionString replaceString = (ReplaceSuggestionString)replaceSuggestionList.Items[index];
                int pos = replaceString.position, len = replaceString.length;
                string word = replaceString.replaceString;
                skipFixing = true;
                richTextBox1.Text = Formatter.replaceWord(text, word, pos, len);
                skipFixing = false;
                richTextBox1.Select(richTextBox1.Text.Length, 0);
                replaceSuggestionList.Items.Clear();
            }
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked) words.setDistanceAlgorithm(new LevenshteinDistance());
            if (radioButton2.Checked) words.setDistanceAlgorithm(new LevenshteinDistanceKeySimilarity());
            if (radioButton3.Checked) words.setDistanceAlgorithm(new NeedlemanWunschAlgo());

        }
    }
}
