namespace OlcChip8Loader
{
    partial class MainForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.configToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.configurePathsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.listBoxRomName = new System.Windows.Forms.ListBox();
            this.labelRomList = new System.Windows.Forms.Label();
            this.buttonPlay = new System.Windows.Forms.Button();
            this.textBoxFColorR = new System.Windows.Forms.TextBox();
            this.labelFColorR = new System.Windows.Forms.Label();
            this.labelFColorG = new System.Windows.Forms.Label();
            this.textBoxFColorG = new System.Windows.Forms.TextBox();
            this.labelFColorB = new System.Windows.Forms.Label();
            this.textBoxFColorB = new System.Windows.Forms.TextBox();
            this.groupBoxFColor = new System.Windows.Forms.GroupBox();
            this.buttonFColor = new System.Windows.Forms.Button();
            this.panelFColor = new System.Windows.Forms.Panel();
            this.labelBColorB = new System.Windows.Forms.Label();
            this.textBoxBColorB = new System.Windows.Forms.TextBox();
            this.labelBColorG = new System.Windows.Forms.Label();
            this.textBoxBColorG = new System.Windows.Forms.TextBox();
            this.labelBColorR = new System.Windows.Forms.Label();
            this.textBoxBColorR = new System.Windows.Forms.TextBox();
            this.groupBoxBColor = new System.Windows.Forms.GroupBox();
            this.buttonBColor = new System.Windows.Forms.Button();
            this.panelBColor = new System.Windows.Forms.Panel();
            this.groupBoxScale = new System.Windows.Forms.GroupBox();
            this.numericUpDownScale = new System.Windows.Forms.NumericUpDown();
            this.labelSacle = new System.Windows.Forms.Label();
            this.labelPx2 = new System.Windows.Forms.Label();
            this.labelPx1 = new System.Windows.Forms.Label();
            this.textBoxHeightPreview = new System.Windows.Forms.TextBox();
            this.labelHeight = new System.Windows.Forms.Label();
            this.textBoxWidthPreview = new System.Windows.Forms.TextBox();
            this.labelPixelWidth = new System.Windows.Forms.Label();
            this.groupBoxPreview = new System.Windows.Forms.GroupBox();
            this.pictureBoxPreview = new System.Windows.Forms.PictureBox();
            this.groupBoxClockRate = new System.Windows.Forms.GroupBox();
            this.trackBarClockRate = new System.Windows.Forms.TrackBar();
            this.labelClockRate = new System.Windows.Forms.Label();
            this.labelHZ = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            this.groupBoxFColor.SuspendLayout();
            this.groupBoxBColor.SuspendLayout();
            this.groupBoxScale.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownScale)).BeginInit();
            this.groupBoxPreview.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxPreview)).BeginInit();
            this.groupBoxClockRate.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarClockRate)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.configToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1172, 25);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(39, 21);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(96, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // configToolStripMenuItem
            // 
            this.configToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.configurePathsToolStripMenuItem});
            this.configToolStripMenuItem.Name = "configToolStripMenuItem";
            this.configToolStripMenuItem.Size = new System.Drawing.Size(58, 21);
            this.configToolStripMenuItem.Text = "Config";
            // 
            // configurePathsToolStripMenuItem
            // 
            this.configurePathsToolStripMenuItem.Name = "configurePathsToolStripMenuItem";
            this.configurePathsToolStripMenuItem.Size = new System.Drawing.Size(177, 22);
            this.configurePathsToolStripMenuItem.Text = "Configure Paths...";
            this.configurePathsToolStripMenuItem.Click += new System.EventHandler(this.configurePathsToolStripMenuItem_Click);
            // 
            // listBoxRomName
            // 
            this.listBoxRomName.FormattingEnabled = true;
            this.listBoxRomName.ItemHeight = 12;
            this.listBoxRomName.Location = new System.Drawing.Point(34, 60);
            this.listBoxRomName.Name = "listBoxRomName";
            this.listBoxRomName.Size = new System.Drawing.Size(307, 604);
            this.listBoxRomName.TabIndex = 1;
            this.listBoxRomName.Click += new System.EventHandler(this.listBoxRomName_Click);
            // 
            // labelRomList
            // 
            this.labelRomList.AutoSize = true;
            this.labelRomList.Location = new System.Drawing.Point(32, 45);
            this.labelRomList.Name = "labelRomList";
            this.labelRomList.Size = new System.Drawing.Size(59, 12);
            this.labelRomList.TabIndex = 2;
            this.labelRomList.Text = "Rom List:";
            // 
            // buttonPlay
            // 
            this.buttonPlay.Location = new System.Drawing.Point(361, 637);
            this.buttonPlay.Name = "buttonPlay";
            this.buttonPlay.Size = new System.Drawing.Size(75, 23);
            this.buttonPlay.TabIndex = 3;
            this.buttonPlay.Text = "Play";
            this.buttonPlay.UseVisualStyleBackColor = true;
            this.buttonPlay.Click += new System.EventHandler(this.buttonPlay_Click);
            // 
            // textBoxFColorR
            // 
            this.textBoxFColorR.Location = new System.Drawing.Point(587, 534);
            this.textBoxFColorR.MaxLength = 3;
            this.textBoxFColorR.Name = "textBoxFColorR";
            this.textBoxFColorR.Size = new System.Drawing.Size(36, 21);
            this.textBoxFColorR.TabIndex = 4;
            this.textBoxFColorR.Text = "255";
            this.textBoxFColorR.TextChanged += new System.EventHandler(this.textBoxColor_TextChanged);
            this.textBoxFColorR.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxColor_KeyPress);
            // 
            // labelFColorR
            // 
            this.labelFColorR.AutoSize = true;
            this.labelFColorR.Location = new System.Drawing.Point(565, 537);
            this.labelFColorR.Name = "labelFColorR";
            this.labelFColorR.Size = new System.Drawing.Size(11, 12);
            this.labelFColorR.TabIndex = 5;
            this.labelFColorR.Text = "R";
            // 
            // labelFColorG
            // 
            this.labelFColorG.AutoSize = true;
            this.labelFColorG.Location = new System.Drawing.Point(634, 537);
            this.labelFColorG.Name = "labelFColorG";
            this.labelFColorG.Size = new System.Drawing.Size(11, 12);
            this.labelFColorG.TabIndex = 7;
            this.labelFColorG.Text = "G";
            // 
            // textBoxFColorG
            // 
            this.textBoxFColorG.Location = new System.Drawing.Point(656, 534);
            this.textBoxFColorG.MaxLength = 3;
            this.textBoxFColorG.Name = "textBoxFColorG";
            this.textBoxFColorG.Size = new System.Drawing.Size(36, 21);
            this.textBoxFColorG.TabIndex = 6;
            this.textBoxFColorG.Text = "255";
            this.textBoxFColorG.TextChanged += new System.EventHandler(this.textBoxColor_TextChanged);
            this.textBoxFColorG.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxColor_KeyPress);
            // 
            // labelFColorB
            // 
            this.labelFColorB.AutoSize = true;
            this.labelFColorB.Location = new System.Drawing.Point(703, 537);
            this.labelFColorB.Name = "labelFColorB";
            this.labelFColorB.Size = new System.Drawing.Size(11, 12);
            this.labelFColorB.TabIndex = 9;
            this.labelFColorB.Text = "B";
            // 
            // textBoxFColorB
            // 
            this.textBoxFColorB.Location = new System.Drawing.Point(725, 534);
            this.textBoxFColorB.MaxLength = 3;
            this.textBoxFColorB.Name = "textBoxFColorB";
            this.textBoxFColorB.Size = new System.Drawing.Size(36, 21);
            this.textBoxFColorB.TabIndex = 8;
            this.textBoxFColorB.Text = "255";
            this.textBoxFColorB.TextChanged += new System.EventHandler(this.textBoxColor_TextChanged);
            this.textBoxFColorB.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxColor_KeyPress);
            // 
            // groupBoxFColor
            // 
            this.groupBoxFColor.Controls.Add(this.buttonFColor);
            this.groupBoxFColor.Controls.Add(this.panelFColor);
            this.groupBoxFColor.Location = new System.Drawing.Point(543, 514);
            this.groupBoxFColor.Name = "groupBoxFColor";
            this.groupBoxFColor.Size = new System.Drawing.Size(430, 59);
            this.groupBoxFColor.TabIndex = 10;
            this.groupBoxFColor.TabStop = false;
            this.groupBoxFColor.Text = "Chip8 Foreground Color";
            // 
            // buttonFColor
            // 
            this.buttonFColor.Location = new System.Drawing.Point(300, 18);
            this.buttonFColor.Name = "buttonFColor";
            this.buttonFColor.Size = new System.Drawing.Size(103, 23);
            this.buttonFColor.TabIndex = 1;
            this.buttonFColor.Text = "Pick Color...";
            this.buttonFColor.UseVisualStyleBackColor = true;
            this.buttonFColor.Click += new System.EventHandler(this.buttonFColor_Click);
            // 
            // panelFColor
            // 
            this.panelFColor.BackColor = System.Drawing.Color.White;
            this.panelFColor.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panelFColor.Location = new System.Drawing.Point(238, 21);
            this.panelFColor.Name = "panelFColor";
            this.panelFColor.Size = new System.Drawing.Size(42, 19);
            this.panelFColor.TabIndex = 0;
            // 
            // labelBColorB
            // 
            this.labelBColorB.AutoSize = true;
            this.labelBColorB.Location = new System.Drawing.Point(703, 624);
            this.labelBColorB.Name = "labelBColorB";
            this.labelBColorB.Size = new System.Drawing.Size(11, 12);
            this.labelBColorB.TabIndex = 16;
            this.labelBColorB.Text = "B";
            // 
            // textBoxBColorB
            // 
            this.textBoxBColorB.Location = new System.Drawing.Point(725, 621);
            this.textBoxBColorB.MaxLength = 3;
            this.textBoxBColorB.Name = "textBoxBColorB";
            this.textBoxBColorB.Size = new System.Drawing.Size(36, 21);
            this.textBoxBColorB.TabIndex = 15;
            this.textBoxBColorB.Text = "0";
            this.textBoxBColorB.TextChanged += new System.EventHandler(this.textBoxColor_TextChanged);
            this.textBoxBColorB.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxColor_KeyPress);
            // 
            // labelBColorG
            // 
            this.labelBColorG.AutoSize = true;
            this.labelBColorG.Location = new System.Drawing.Point(634, 624);
            this.labelBColorG.Name = "labelBColorG";
            this.labelBColorG.Size = new System.Drawing.Size(11, 12);
            this.labelBColorG.TabIndex = 14;
            this.labelBColorG.Text = "G";
            // 
            // textBoxBColorG
            // 
            this.textBoxBColorG.Location = new System.Drawing.Point(656, 621);
            this.textBoxBColorG.MaxLength = 3;
            this.textBoxBColorG.Name = "textBoxBColorG";
            this.textBoxBColorG.Size = new System.Drawing.Size(36, 21);
            this.textBoxBColorG.TabIndex = 13;
            this.textBoxBColorG.Text = "0";
            this.textBoxBColorG.TextChanged += new System.EventHandler(this.textBoxColor_TextChanged);
            this.textBoxBColorG.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxColor_KeyPress);
            // 
            // labelBColorR
            // 
            this.labelBColorR.AutoSize = true;
            this.labelBColorR.Location = new System.Drawing.Point(565, 624);
            this.labelBColorR.Name = "labelBColorR";
            this.labelBColorR.Size = new System.Drawing.Size(11, 12);
            this.labelBColorR.TabIndex = 12;
            this.labelBColorR.Text = "R";
            // 
            // textBoxBColorR
            // 
            this.textBoxBColorR.Location = new System.Drawing.Point(587, 621);
            this.textBoxBColorR.MaxLength = 3;
            this.textBoxBColorR.Name = "textBoxBColorR";
            this.textBoxBColorR.Size = new System.Drawing.Size(36, 21);
            this.textBoxBColorR.TabIndex = 11;
            this.textBoxBColorR.Text = "0";
            this.textBoxBColorR.TextChanged += new System.EventHandler(this.textBoxColor_TextChanged);
            this.textBoxBColorR.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxColor_KeyPress);
            // 
            // groupBoxBColor
            // 
            this.groupBoxBColor.Controls.Add(this.buttonBColor);
            this.groupBoxBColor.Controls.Add(this.panelBColor);
            this.groupBoxBColor.Location = new System.Drawing.Point(543, 601);
            this.groupBoxBColor.Name = "groupBoxBColor";
            this.groupBoxBColor.Size = new System.Drawing.Size(430, 59);
            this.groupBoxBColor.TabIndex = 17;
            this.groupBoxBColor.TabStop = false;
            this.groupBoxBColor.Text = "Chip8 Background Color";
            // 
            // buttonBColor
            // 
            this.buttonBColor.Location = new System.Drawing.Point(300, 18);
            this.buttonBColor.Name = "buttonBColor";
            this.buttonBColor.Size = new System.Drawing.Size(103, 23);
            this.buttonBColor.TabIndex = 1;
            this.buttonBColor.Text = "Pick Color...";
            this.buttonBColor.UseVisualStyleBackColor = true;
            this.buttonBColor.Click += new System.EventHandler(this.buttonBColor_Click);
            // 
            // panelBColor
            // 
            this.panelBColor.BackColor = System.Drawing.Color.Black;
            this.panelBColor.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panelBColor.Location = new System.Drawing.Point(238, 21);
            this.panelBColor.Name = "panelBColor";
            this.panelBColor.Size = new System.Drawing.Size(42, 19);
            this.panelBColor.TabIndex = 0;
            // 
            // groupBoxScale
            // 
            this.groupBoxScale.Controls.Add(this.numericUpDownScale);
            this.groupBoxScale.Controls.Add(this.labelSacle);
            this.groupBoxScale.Controls.Add(this.labelPx2);
            this.groupBoxScale.Controls.Add(this.labelPx1);
            this.groupBoxScale.Controls.Add(this.textBoxHeightPreview);
            this.groupBoxScale.Controls.Add(this.labelHeight);
            this.groupBoxScale.Controls.Add(this.textBoxWidthPreview);
            this.groupBoxScale.Controls.Add(this.labelPixelWidth);
            this.groupBoxScale.Location = new System.Drawing.Point(543, 430);
            this.groupBoxScale.Name = "groupBoxScale";
            this.groupBoxScale.Size = new System.Drawing.Size(430, 59);
            this.groupBoxScale.TabIndex = 19;
            this.groupBoxScale.TabStop = false;
            this.groupBoxScale.Text = "Chip8 Display screen scale factor";
            // 
            // numericUpDownScale
            // 
            this.numericUpDownScale.Location = new System.Drawing.Point(67, 21);
            this.numericUpDownScale.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownScale.Name = "numericUpDownScale";
            this.numericUpDownScale.Size = new System.Drawing.Size(47, 21);
            this.numericUpDownScale.TabIndex = 20;
            this.numericUpDownScale.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownScale.ValueChanged += new System.EventHandler(this.numericUpDownScale_ValueChanged);
            // 
            // labelSacle
            // 
            this.labelSacle.AutoSize = true;
            this.labelSacle.Location = new System.Drawing.Point(20, 25);
            this.labelSacle.Name = "labelSacle";
            this.labelSacle.Size = new System.Drawing.Size(41, 12);
            this.labelSacle.TabIndex = 25;
            this.labelSacle.Text = "scale:";
            // 
            // labelPx2
            // 
            this.labelPx2.AutoSize = true;
            this.labelPx2.Location = new System.Drawing.Point(397, 25);
            this.labelPx2.Name = "labelPx2";
            this.labelPx2.Size = new System.Drawing.Size(17, 12);
            this.labelPx2.TabIndex = 24;
            this.labelPx2.Text = "px";
            // 
            // labelPx1
            // 
            this.labelPx1.AutoSize = true;
            this.labelPx1.Location = new System.Drawing.Point(247, 24);
            this.labelPx1.Name = "labelPx1";
            this.labelPx1.Size = new System.Drawing.Size(17, 12);
            this.labelPx1.TabIndex = 23;
            this.labelPx1.Text = "px";
            // 
            // textBoxHeightPreview
            // 
            this.textBoxHeightPreview.Location = new System.Drawing.Point(328, 21);
            this.textBoxHeightPreview.Name = "textBoxHeightPreview";
            this.textBoxHeightPreview.ReadOnly = true;
            this.textBoxHeightPreview.Size = new System.Drawing.Size(63, 21);
            this.textBoxHeightPreview.TabIndex = 22;
            this.textBoxHeightPreview.Text = "320";
            this.textBoxHeightPreview.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // labelHeight
            // 
            this.labelHeight.AutoSize = true;
            this.labelHeight.Location = new System.Drawing.Point(280, 25);
            this.labelHeight.Name = "labelHeight";
            this.labelHeight.Size = new System.Drawing.Size(47, 12);
            this.labelHeight.TabIndex = 21;
            this.labelHeight.Text = "height:";
            // 
            // textBoxWidthPreview
            // 
            this.textBoxWidthPreview.Location = new System.Drawing.Point(178, 21);
            this.textBoxWidthPreview.Name = "textBoxWidthPreview";
            this.textBoxWidthPreview.ReadOnly = true;
            this.textBoxWidthPreview.Size = new System.Drawing.Size(63, 21);
            this.textBoxWidthPreview.TabIndex = 20;
            this.textBoxWidthPreview.Text = "640";
            this.textBoxWidthPreview.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // labelPixelWidth
            // 
            this.labelPixelWidth.AutoSize = true;
            this.labelPixelWidth.Location = new System.Drawing.Point(130, 25);
            this.labelPixelWidth.Name = "labelPixelWidth";
            this.labelPixelWidth.Size = new System.Drawing.Size(41, 12);
            this.labelPixelWidth.TabIndex = 19;
            this.labelPixelWidth.Text = "width:";
            // 
            // groupBoxPreview
            // 
            this.groupBoxPreview.Controls.Add(this.pictureBoxPreview);
            this.groupBoxPreview.Location = new System.Drawing.Point(543, 60);
            this.groupBoxPreview.Name = "groupBoxPreview";
            this.groupBoxPreview.Size = new System.Drawing.Size(454, 244);
            this.groupBoxPreview.TabIndex = 20;
            this.groupBoxPreview.TabStop = false;
            this.groupBoxPreview.Text = "Preview";
            // 
            // pictureBoxPreview
            // 
            this.pictureBoxPreview.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBoxPreview.Location = new System.Drawing.Point(3, 17);
            this.pictureBoxPreview.Name = "pictureBoxPreview";
            this.pictureBoxPreview.Size = new System.Drawing.Size(448, 224);
            this.pictureBoxPreview.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBoxPreview.TabIndex = 0;
            this.pictureBoxPreview.TabStop = false;
            // 
            // groupBoxClockRate
            // 
            this.groupBoxClockRate.Controls.Add(this.labelHZ);
            this.groupBoxClockRate.Controls.Add(this.labelClockRate);
            this.groupBoxClockRate.Controls.Add(this.trackBarClockRate);
            this.groupBoxClockRate.Location = new System.Drawing.Point(543, 335);
            this.groupBoxClockRate.Name = "groupBoxClockRate";
            this.groupBoxClockRate.Size = new System.Drawing.Size(430, 77);
            this.groupBoxClockRate.TabIndex = 21;
            this.groupBoxClockRate.TabStop = false;
            this.groupBoxClockRate.Text = "Cpu Rate";
            // 
            // trackBarClockRate
            // 
            this.trackBarClockRate.LargeChange = 100;
            this.trackBarClockRate.Location = new System.Drawing.Point(15, 30);
            this.trackBarClockRate.Maximum = 1000;
            this.trackBarClockRate.Minimum = 1;
            this.trackBarClockRate.Name = "trackBarClockRate";
            this.trackBarClockRate.Size = new System.Drawing.Size(312, 45);
            this.trackBarClockRate.TabIndex = 0;
            this.trackBarClockRate.TickFrequency = 100;
            this.trackBarClockRate.Value = 500;
            this.trackBarClockRate.ValueChanged += new System.EventHandler(this.trackBarClockRate_ValueChanged);
            // 
            // labelClockRate
            // 
            this.labelClockRate.AutoSize = true;
            this.labelClockRate.Location = new System.Drawing.Point(334, 39);
            this.labelClockRate.Name = "labelClockRate";
            this.labelClockRate.Size = new System.Drawing.Size(23, 12);
            this.labelClockRate.TabIndex = 1;
            this.labelClockRate.Text = "500";
            // 
            // labelHZ
            // 
            this.labelHZ.AutoSize = true;
            this.labelHZ.Location = new System.Drawing.Point(364, 39);
            this.labelHZ.Name = "labelHZ";
            this.labelHZ.Size = new System.Drawing.Size(17, 12);
            this.labelHZ.TabIndex = 2;
            this.labelHZ.Text = "HZ";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1172, 769);
            this.Controls.Add(this.groupBoxClockRate);
            this.Controls.Add(this.groupBoxPreview);
            this.Controls.Add(this.labelBColorB);
            this.Controls.Add(this.textBoxBColorB);
            this.Controls.Add(this.labelBColorG);
            this.Controls.Add(this.textBoxBColorG);
            this.Controls.Add(this.labelBColorR);
            this.Controls.Add(this.textBoxBColorR);
            this.Controls.Add(this.groupBoxBColor);
            this.Controls.Add(this.labelFColorB);
            this.Controls.Add(this.textBoxFColorB);
            this.Controls.Add(this.labelFColorG);
            this.Controls.Add(this.textBoxFColorG);
            this.Controls.Add(this.labelFColorR);
            this.Controls.Add(this.textBoxFColorR);
            this.Controls.Add(this.buttonPlay);
            this.Controls.Add(this.labelRomList);
            this.Controls.Add(this.listBoxRomName);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.groupBoxFColor);
            this.Controls.Add(this.groupBoxScale);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainForm";
            this.Text = "OlcChip8 Loader";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.MainForm_FormClosed);
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.groupBoxFColor.ResumeLayout(false);
            this.groupBoxBColor.ResumeLayout(false);
            this.groupBoxScale.ResumeLayout(false);
            this.groupBoxScale.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownScale)).EndInit();
            this.groupBoxPreview.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxPreview)).EndInit();
            this.groupBoxClockRate.ResumeLayout(false);
            this.groupBoxClockRate.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarClockRate)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem configToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem configurePathsToolStripMenuItem;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.ListBox listBoxRomName;
        private System.Windows.Forms.Label labelRomList;
        private System.Windows.Forms.Button buttonPlay;
        private System.Windows.Forms.TextBox textBoxFColorR;
        private System.Windows.Forms.Label labelFColorR;
        private System.Windows.Forms.Label labelFColorG;
        private System.Windows.Forms.TextBox textBoxFColorG;
        private System.Windows.Forms.Label labelFColorB;
        private System.Windows.Forms.TextBox textBoxFColorB;
        private System.Windows.Forms.GroupBox groupBoxFColor;
        private System.Windows.Forms.Button buttonFColor;
        private System.Windows.Forms.Panel panelFColor;
        private System.Windows.Forms.Label labelBColorB;
        private System.Windows.Forms.TextBox textBoxBColorB;
        private System.Windows.Forms.Label labelBColorG;
        private System.Windows.Forms.TextBox textBoxBColorG;
        private System.Windows.Forms.Label labelBColorR;
        private System.Windows.Forms.TextBox textBoxBColorR;
        private System.Windows.Forms.GroupBox groupBoxBColor;
        private System.Windows.Forms.Button buttonBColor;
        private System.Windows.Forms.Panel panelBColor;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.GroupBox groupBoxScale;
        private System.Windows.Forms.Label labelSacle;
        private System.Windows.Forms.Label labelPx2;
        private System.Windows.Forms.Label labelPx1;
        private System.Windows.Forms.TextBox textBoxHeightPreview;
        private System.Windows.Forms.Label labelHeight;
        private System.Windows.Forms.TextBox textBoxWidthPreview;
        private System.Windows.Forms.Label labelPixelWidth;
        private System.Windows.Forms.NumericUpDown numericUpDownScale;
        private System.Windows.Forms.GroupBox groupBoxPreview;
        private System.Windows.Forms.PictureBox pictureBoxPreview;
        private System.Windows.Forms.GroupBox groupBoxClockRate;
        private System.Windows.Forms.TrackBar trackBarClockRate;
        private System.Windows.Forms.Label labelClockRate;
        private System.Windows.Forms.Label labelHZ;
    }
}

