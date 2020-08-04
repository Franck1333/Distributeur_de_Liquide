---


---

<h1 id="dht11_voitures">DHT11_Voitures</h1>
<p>This small project allow me to get a numeric Thermometer in my ancient car.<br>
Those days, I want to modernize my old car by adding electronics by myself.<br>
This arduino project is in fact usable everywhere but that’s gave me a pretext for the realisation of this project in my old car.<br>
By the way, this project gave me the opportunity to code in a language that i’m not used to and also to conceive a PCB on software and realize it at the end.<br>
To finish, I want to make a final product usable by anyone by conceive and product a case by a 3D printer.</p>
<p><a href="https://www.hostpic.org/images/2003192355070085.jpg"><img src="https://www.hostpic.org/images/2003192355070085.jpg" alt="Image"></a></p>
<h2 id="getting-started">Getting Started</h2>
<p>To get a copy of the project, you can go on the GitHub’s webpage of the project and click on the green button to download as a .ZIP file. However, if you’re using a prompt console on an Unix machine use this line :</p>
<pre><code>git clone https://github.com/Franck1333/DHT11_Voitures.git
</code></pre>
<h3 id="prerequisites">Prerequisites</h3>
<p>To use the project, you will need some Hardware :</p>
<pre><code>An Arduino Board	(here: Arduino Nano, https://tinyurl.com/arduinoMiniboards)
An OLED Screen 		(here: 128 x 64, https://tinyurl.com/oledscreenarduino)
A DHT11 Sensor		(here: Mine got 3 Pins but this one in the link will work as well, https://tinyurl.com/DHT11sensor4p)
A LED
</code></pre>
<p><em>Also, a breadboard or PCB and also Wires and tools needed to solder.</em></p>
<p>And you will also need some libraries and softwares :</p>
<pre><code>- An Arduino IDE Up to date
- An Arduino board
</code></pre>
<h3 id="downloadinginstalling">Downloading/Installing</h3>
<p>To get and downloaded the files, use this line :</p>
<pre><code>git clone https://github.com/Franck1333/DHT11_Voitures.git
</code></pre>
<p>When the project is Downloaded, check your <code>pi</code> folder, and you will see the folder <code>DHT11_Voitures</code> .</p>
<h2 id="run">Run</h2>
<h4 id="the-way-to-run-the-project-">The Way to run the project :</h4>
<ol>
<li>
<p>To run the project; You need to compile and upload the Source code<br>
to the Arduino Board by using the Arduino IDE<br>
<a href="https://lh3.googleusercontent.com/proxy/R2MVtAhWmxEYWMQLCqzX9hbhT42FRQCsJe-pzIeg0gEa3ZbskhIXDgA2pzVqh0GLFNM3Ov4owDHpF2Wb0QXwtndRyCoIvBU_DtgTcIND_DQ9uzxgXsuffzFyhQ"><img src="https://lh3.googleusercontent.com/proxy/R2MVtAhWmxEYWMQLCqzX9hbhT42FRQCsJe-pzIeg0gEa3ZbskhIXDgA2pzVqh0GLFNM3Ov4owDHpF2Wb0QXwtndRyCoIvBU_DtgTcIND_DQ9uzxgXsuffzFyhQ" alt="Image"></a></p>
</li>
<li>
<p>When it’s done, you should assembly all the component on a<br>
breadboard or solder all the components on a PCB<br>
<a href="https://i.ibb.co/9c7R5ZJ/DHT11-Scheme.png"><img src="https://i.ibb.co/9c7R5ZJ/DHT11-Scheme.png" alt="Image"></a></p>
</li>
<li>
<p>When the last step is done, You must Power on by pluggin an USB power source to your Arduino boards and if you didn’t make any mistakes , It’s Works.<br>
<a href="https://i.ibb.co/fdc4Pwq/IMG-20200319-165632-2.jpg"><img src="https://i.ibb.co/fdc4Pwq/IMG-20200319-165632-2.jpg" alt="Image"></a></p>
</li>
</ol>
<h2 id="running-the-tests">Running the tests</h2>
<p>That’s how to test the program:<br>
Use the Arduino IDE with your files</p>
<pre><code>&lt;file&gt;.ino
</code></pre>
<h2 id="the-folders-and-files">The Folders and Files</h2>
<p>In this project we’ve got some folders</p>
<h4 id="folders">Folders</h4>
<pre><code>- 3D_Model: 3D Files needed to create a cases for the Thermometer.
- Documents_Fritzing: Files used to conceive and assembly all the component.
- Lib: Library used by the main program.
- Pictures: Pictures of the project.
</code></pre>
<h4 id="files-in-dht11_voitures">Files in “/DHT11_Voitures/”</h4>
<p>Main features of the program</p>
<pre><code>- Voitures_DHT11.ino: That's main program.
- Scheme_DHT11.pdf: That's the scheme of the numeric thermometer.
- Components_list.html: This is the list of components needed for this project.
</code></pre>
<h2 id="authors">Authors</h2>
<ul>
<li><strong>Franck ROCHAT</strong>  -  <em>Initial work</em>  -  <a href="https://github.com/Franck1333">Franck ROCHAT</a>  Thank You !  ❤️<br>
<a href="https://www.hostpic.org/images/2003192356230089.jpg"><img src="https://www.hostpic.org/images/2003192356230089.jpg" alt="Image"></a></li>
</ul>

