using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics;
using System.Xml;

namespace OlcChip8Loader
{
    public partial class MainForm : Form
    {
        string olcChip8ExePath;
        string chip8RomsPath;
        Process process;

        const int chip8ScreenWidth = 64;
        const int chip8ScreenHeight = 32;

        bool isEmuRunning = false;
        string warmMsgEmuIsRunning = "Emulator is Running!";
        string warmMsgNoSettingFile = "Can't found setting File, please configure paths first!";
        string errMsgNoSaveSetting = "Can't Save Setting To ";
        string errMsgNoLoadSetting = "Can't Load Setting From ";

        public MainForm()
        {
            InitializeComponent();
        }

        private void buttonPlay_Click(object sender, EventArgs e)
        {
            if (listBoxRomName.SelectedItem == null)
            {
                return;
            }
            string romFileFullName;
            romFileFullName = chip8RomsPath +  "\\" + listBoxRomName.SelectedItem.ToString();
            int fr = Convert.ToInt32(textBoxFColorR.Text);
            int fg = Convert.ToInt32(textBoxFColorG.Text);
            int fb = Convert.ToInt32(textBoxFColorB.Text);
            int br = Convert.ToInt32(textBoxBColorR.Text);
            int bg = Convert.ToInt32(textBoxBColorG.Text);
            int bb = Convert.ToInt32(textBoxBColorB.Text);

            RunEmulator(romFileFullName, fr, fg, fb, br, bg, bb, Convert.ToInt32(numericUpDownScale.Value), trackBarClockRate.Value);
        }

        private void configurePathsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenConfigPathFormAndLoadRomsToListbox();
        }

        private void OpenConfigPathFormAndLoadRomsToListbox()
        {
            using (ConfigPathForm configPathForm = new ConfigPathForm())
            {
                configPathForm.StartPosition = FormStartPosition.CenterParent;
                configPathForm.OlcChip8ExePath = olcChip8ExePath;
                configPathForm.Chip8RomsPath = chip8RomsPath;

                if (configPathForm.ShowDialog(this) == DialogResult.OK)
                {
                    olcChip8ExePath = configPathForm.OlcChip8ExePath;
                    chip8RomsPath = configPathForm.Chip8RomsPath;
                    string path = Application.StartupPath + "\\setting.xml";

                    try
                    {
                        XmlDocument xml = new XmlDocument();
                        xml.AppendChild(xml.CreateXmlDeclaration("1.0", "utf-8", ""));
                        XmlElement root = xml.CreateElement("OlcChip8Loader");

                        XmlElement exePath = xml.CreateElement("OlcChip8ExePath");
                        exePath.InnerText = olcChip8ExePath;
                        root.AppendChild(exePath);

                        XmlElement romsPath = xml.CreateElement("Chip8RomsPath");
                        romsPath.InnerText = chip8RomsPath;
                        root.AppendChild(romsPath);
                        xml.AppendChild(root);
                        xml.Save(path);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(this, ex.ToString(), errMsgNoSaveSetting + path);
                    }

                    LoadRomsNameToListBox();
                }

            }
            
        }


        private void RunEmulator(string romFileName, int foregroundColorR, int foregroundColorG, int foregroundColorB, int backgroundColorR, int backgroundColorG, int backgroundColorB, int scale, int cpuClockRate)
        {
            if (isEmuRunning)
            {
                MessageBox.Show(this, warmMsgEmuIsRunning);
                return;
            }
            try
            {
                process = new Process();
                process.StartInfo.FileName = olcChip8ExePath;
                string paramForegroundColor = "-f " + foregroundColorR.ToString().PadLeft(3, '0') + foregroundColorG.ToString().PadLeft(3, '0') + foregroundColorB.ToString().PadLeft(3, '0');
                string paramBackgroundColor = " -b " + backgroundColorR.ToString().PadLeft(3, '0') + backgroundColorG.ToString().PadLeft(3, '0') + backgroundColorB.ToString().PadLeft(3, '0');
                string paramScale = " -s " + numericUpDownScale.Value.ToString();
                string paramClockRate = " -c " + cpuClockRate.ToString() + " ";
                process.StartInfo.Arguments = paramForegroundColor + paramBackgroundColor + paramScale + paramClockRate + romFileName;
                process.EnableRaisingEvents = true;
                process.Exited += new EventHandler(Process_Exited);
                isEmuRunning = process.Start();
            }
            catch (Exception ex)
            {
                MessageBox.Show(this, ex.ToString());
            }
        }

        private void Process_Exited(object sender, EventArgs e)
        {
            isEmuRunning = false;
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
   
            if (File.Exists(Application.StartupPath + "\\setting.xml"))
            {
                string path = Application.StartupPath + "\\setting.xml";
                try
                { 
                    XmlDocument xml = new XmlDocument();
                    xml.Load(path);
                    XmlNode root = xml.SelectSingleNode("OlcChip8Loader");
                    olcChip8ExePath = root.SelectSingleNode("OlcChip8ExePath").InnerText;
                    chip8RomsPath = root.SelectSingleNode("Chip8RomsPath").InnerText;
                    LoadRomsNameToListBox();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(this, ex.ToString(), errMsgNoLoadSetting + path);
                }
            }
            else
            {
                MessageBox.Show(this, warmMsgNoSettingFile);
                OpenConfigPathFormAndLoadRomsToListbox();
            }
        }

        private void buttonBColor_Click(object sender, EventArgs e)
        {
            colorDialog1.Color = Color.FromArgb(Convert.ToInt32(textBoxBColorR.Text), Convert.ToInt32(textBoxBColorG.Text), Convert.ToInt32(textBoxBColorB.Text));
            colorDialog1.FullOpen = true;
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                textBoxBColorR.Text = colorDialog1.Color.R.ToString();
                textBoxBColorG.Text = colorDialog1.Color.G.ToString();
                textBoxBColorB.Text = colorDialog1.Color.B.ToString();

                panelBColor.BackColor = Color.FromArgb(colorDialog1.Color.R, colorDialog1.Color.G, colorDialog1.Color.B);

            }
        }

        private void textBoxColor_KeyPress(object sender, KeyPressEventArgs e)
        {
            
            if ((e.KeyChar < 48 || e.KeyChar > 57) && !char.IsControl(e.KeyChar))
            {
                e.Handled = true;
            }
        }

        private void numericUpDownScale_ValueChanged(object sender, EventArgs e)
        {
            textBoxWidthPreview.Text = (numericUpDownScale.Value * chip8ScreenWidth).ToString();
            textBoxHeightPreview.Text = (numericUpDownScale.Value * chip8ScreenHeight).ToString();
        }

        private void LoadRomsNameToListBox()
        {
            if (Directory.Exists(chip8RomsPath))
            {
                listBoxRomName.Items.Clear();
                DirectoryInfo dirInfo = new DirectoryInfo(chip8RomsPath);
                FileInfo[] romFileNames = dirInfo.GetFiles("*.*");
                foreach (FileInfo fi in romFileNames)
                {
                    listBoxRomName.Items.Add(fi.Name);
                }
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {

            this.Close();
        }

        private void buttonFColor_Click(object sender, EventArgs e)
        {
            colorDialog1.Color = Color.FromArgb(Convert.ToInt32(textBoxFColorR.Text), Convert.ToInt32(textBoxFColorG.Text), Convert.ToInt32(textBoxFColorB.Text));
            colorDialog1.FullOpen = true;
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                textBoxFColorR.Text = colorDialog1.Color.R.ToString();
                textBoxFColorG.Text = colorDialog1.Color.G.ToString();
                textBoxFColorB.Text = colorDialog1.Color.B.ToString();

                panelFColor.BackColor = Color.FromArgb(colorDialog1.Color.R, colorDialog1.Color.G, colorDialog1.Color.B);

            }
        }

        private void textBoxColor_TextChanged(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
            else
            {
                int value = Convert.ToInt32(((TextBox)sender).Text);
                if (value > 255)
                    ((TextBox)sender).Text = "255";
            }
            panelFColor.BackColor = Color.FromArgb(Convert.ToInt32(textBoxFColorR.Text), Convert.ToInt32(textBoxFColorG.Text), Convert.ToInt32(textBoxFColorB.Text));
            panelBColor.BackColor = Color.FromArgb(Convert.ToInt32(textBoxBColorR.Text), Convert.ToInt32(textBoxBColorG.Text), Convert.ToInt32(textBoxBColorB.Text));
        }

        private void MainForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (isEmuRunning)
            {
                process.Kill();
            }
        }

        private void listBoxRomName_Click(object sender, EventArgs e)
        {
            string picName = Application.StartupPath + "\\preview\\" + listBoxRomName.SelectedItem.ToString() + ".png";
            if (File.Exists(picName))
            {
                pictureBoxPreview.Image = Image.FromFile(picName);
            }
        }

        private void trackBarClockRate_ValueChanged(object sender, EventArgs e)
        {
            labelClockRate.Text = trackBarClockRate.Value.ToString();
        }
    }
}
