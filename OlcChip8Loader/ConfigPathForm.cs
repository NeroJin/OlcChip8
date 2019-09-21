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

namespace OlcChip8Loader
{
    public partial class ConfigPathForm : Form
    {
        public string OlcChip8ExePath
        {
            set;
            get;
        }

        public string Chip8RomsPath
        {
            set;
            get;
        }

        private string errMsgExePathNull = "OlcChip8 emulator executable file is empty!";
        private string errMsgRomsPathNull = "Chip8 roms path is empty!";
        private string errMsgExeFileNotExist = "OlcChip8 emulator executable file is not exist!";
        private string errMsgRomsPathNotExist = "Chip8 roms path is not exist!";

        public ConfigPathForm()
        {
            InitializeComponent();
            OlcChip8ExePath = string.Empty;
            Chip8RomsPath = string.Empty;
        }

        private void buttonChip8ExePathBrowse_Click(object sender, EventArgs e)
        {
            openFileDialog1.Title = "Select OlcChip8 Emulator EXE File";
            openFileDialog1.DefaultExt = "exe";
            openFileDialog1.Filter = "Exe files (*.exe)|*.exe|All files (*.*)|*.*";
            openFileDialog1.FileName = "OlcChip8.exe";
            
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                textBoxChip8ExePath.Text = openFileDialog1.FileName;
                
            }
        }

        private void buttonChip8RomsBrowse_Click(object sender, EventArgs e)
        {
            if (folderBrowserDialog1.ShowDialog() == DialogResult.OK)
            {
                textBoxChip8Roms.Text = folderBrowserDialog1.SelectedPath;
                
            }
        }


        private void buttonOk_Click(object sender, EventArgs e)
        {
            if (textBoxChip8ExePath.Text == string.Empty)
            {
                MessageBox.Show(this, errMsgExePathNull);
            }
            else if (textBoxChip8ExePath.Text == string.Empty)
            {
                MessageBox.Show(this, errMsgRomsPathNull);
            }
            else if (!File.Exists(textBoxChip8ExePath.Text))
            {
                MessageBox.Show(this, errMsgExeFileNotExist);
            }
            else if (!Directory.Exists(textBoxChip8Roms.Text))
            {
                MessageBox.Show(this, errMsgRomsPathNotExist);
            }
            else
            {
                OlcChip8ExePath = textBoxChip8ExePath.Text;
                Chip8RomsPath = textBoxChip8Roms.Text;

                this.DialogResult = DialogResult.OK;
            }

        }

        private void ConfigPathForm_Load(object sender, EventArgs e)
        {
            if (File.Exists(OlcChip8ExePath))
                textBoxChip8ExePath.Text = OlcChip8ExePath;
            if (Directory.Exists(Chip8RomsPath))
                textBoxChip8Roms.Text = Chip8RomsPath;
        }
    }
}
