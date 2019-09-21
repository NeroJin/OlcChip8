namespace OlcChip8Loader
{
    partial class ConfigPathForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.textBoxChip8ExePath = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonChip8ExePathBrowse = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxChip8Roms = new System.Windows.Forms.TextBox();
            this.buttonChip8RomsBrowse = new System.Windows.Forms.Button();
            this.folderBrowserDialog1 = new System.Windows.Forms.FolderBrowserDialog();
            this.buttonOk = new System.Windows.Forms.Button();
            this.buttonCancel = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBoxChip8ExePath
            // 
            this.textBoxChip8ExePath.Location = new System.Drawing.Point(35, 56);
            this.textBoxChip8ExePath.Name = "textBoxChip8ExePath";
            this.textBoxChip8ExePath.Size = new System.Drawing.Size(464, 21);
            this.textBoxChip8ExePath.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(33, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(143, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = "OlcChip8 emulator path:";
            // 
            // buttonChip8ExePathBrowse
            // 
            this.buttonChip8ExePathBrowse.Location = new System.Drawing.Point(536, 54);
            this.buttonChip8ExePathBrowse.Name = "buttonChip8ExePathBrowse";
            this.buttonChip8ExePathBrowse.Size = new System.Drawing.Size(75, 23);
            this.buttonChip8ExePathBrowse.TabIndex = 2;
            this.buttonChip8ExePathBrowse.Text = "Browse...";
            this.buttonChip8ExePathBrowse.UseVisualStyleBackColor = true;
            this.buttonChip8ExePathBrowse.Click += new System.EventHandler(this.buttonChip8ExePathBrowse_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(33, 109);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(101, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "Chip8 roms path:";
            // 
            // textBoxChip8Roms
            // 
            this.textBoxChip8Roms.Location = new System.Drawing.Point(35, 134);
            this.textBoxChip8Roms.Name = "textBoxChip8Roms";
            this.textBoxChip8Roms.Size = new System.Drawing.Size(464, 21);
            this.textBoxChip8Roms.TabIndex = 4;
            // 
            // buttonChip8RomsBrowse
            // 
            this.buttonChip8RomsBrowse.Location = new System.Drawing.Point(536, 132);
            this.buttonChip8RomsBrowse.Name = "buttonChip8RomsBrowse";
            this.buttonChip8RomsBrowse.Size = new System.Drawing.Size(75, 23);
            this.buttonChip8RomsBrowse.TabIndex = 5;
            this.buttonChip8RomsBrowse.Text = "Browse...";
            this.buttonChip8RomsBrowse.UseVisualStyleBackColor = true;
            this.buttonChip8RomsBrowse.Click += new System.EventHandler(this.buttonChip8RomsBrowse_Click);
            // 
            // buttonOk
            // 
            this.buttonOk.Location = new System.Drawing.Point(444, 183);
            this.buttonOk.Name = "buttonOk";
            this.buttonOk.Size = new System.Drawing.Size(75, 23);
            this.buttonOk.TabIndex = 6;
            this.buttonOk.Text = "OK";
            this.buttonOk.UseVisualStyleBackColor = true;
            this.buttonOk.Click += new System.EventHandler(this.buttonOk_Click);
            // 
            // buttonCancel
            // 
            this.buttonCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.buttonCancel.Location = new System.Drawing.Point(553, 183);
            this.buttonCancel.Name = "buttonCancel";
            this.buttonCancel.Size = new System.Drawing.Size(75, 23);
            this.buttonCancel.TabIndex = 7;
            this.buttonCancel.Text = "Cancel";
            this.buttonCancel.UseVisualStyleBackColor = true;
            // 
            // ConfigPathForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(655, 235);
            this.Controls.Add(this.buttonCancel);
            this.Controls.Add(this.buttonOk);
            this.Controls.Add(this.buttonChip8RomsBrowse);
            this.Controls.Add(this.textBoxChip8Roms);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.buttonChip8ExePathBrowse);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxChip8ExePath);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ConfigPathForm";
            this.Text = "Configure Paths";
            this.Load += new System.EventHandler(this.ConfigPathForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxChip8ExePath;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonChip8ExePathBrowse;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxChip8Roms;
        private System.Windows.Forms.Button buttonChip8RomsBrowse;
        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog1;
        private System.Windows.Forms.Button buttonOk;
        private System.Windows.Forms.Button buttonCancel;
    }
}