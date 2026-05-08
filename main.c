<!DOCTYPE html><html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>SPRAS - Student Performance Risk Alert System</title>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.1/css/all.min.css">
<script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
<style>
*{
margin:0;
padding:0;
box-sizing:border-box;
font-family:Arial,sans-serif;
}body{ background:#f4f7fc; color:#333; }

header{ background:#111827; color:white; padding:20px 50px; display:flex; justify-content:space-between; align-items:center; position:sticky; top:0; z-index:1000; }

header h1{ font-size:28px; }

nav a{ color:white; margin-left:20px; text-decoration:none; font-weight:bold; }

.hero{ height:90vh; background:linear-gradient(to right,#1e3c72,#2a5298); color:white; display:flex; flex-direction:column; justify-content:center; align-items:center; text-align:center; padding:20px; }

.hero h2{ font-size:60px; margin-bottom:20px; }

.hero p{ font-size:22px; max-width:800px; line-height:1.6; }

.btn{ margin-top:30px; padding:15px 35px; background:white; color:#1e3c72; border:none; border-radius:10px; font-size:18px; cursor:pointer; font-weight:bold; transition:0.3s; }

.btn:hover{ transform:scale(1.05); background:#ddd; }

section{ padding:80px 50px; }

.section-title{ text-align:center; font-size:40px; margin-bottom:50px; color:#1e3c72; }

.cards{ display:grid; grid-template-columns:repeat(auto-fit,minmax(250px,1fr)); gap:25px; }

.card{ background:white; padding:30px; border-radius:15px; box-shadow:0 5px 15px rgba(0,0,0,0.1); transition:0.3s; cursor:pointer; }

.card:hover{ transform:translateY(-10px); }

.card i{ font-size:40px; margin-bottom:20px; color:#1e3c72; }

.dashboard{ background:white; padding:40px; border-radius:15px; box-shadow:0 5px 15px rgba(0,0,0,0.1); }

.stats{ display:flex; justify-content:space-around; flex-wrap:wrap; margin-bottom:40px; }

.stat-box{ background:#1e3c72; color:white; padding:25px; border-radius:15px; width:220px; text-align:center; margin:10px; }

.upload-box{ background:white; padding:40px; border-radius:15px; text-align:center; box-shadow:0 5px 15px rgba(0,0,0,0.1); }

.upload-box input{ margin:20px 0; }

.team{ display:grid; grid-template-columns:repeat(auto-fit,minmax(250px,1fr)); gap:25px; }

.member{ background:white; padding:25px; border-radius:15px; text-align:center; box-shadow:0 5px 15px rgba(0,0,0,0.1); }

footer{ background:#111827; color:white; text-align:center; padding:20px; margin-top:40px; }

@media(max-width:768px){ .hero h2{ font-size:40px; }

.stats{ flex-direction:column; align-items:center; } } </style>

</head>
<body><header>
<h1>SPRAS 🚀</h1>
<nav>
<a href="#home">Home</a>
<a href="#features">Features</a>
<a href="#dashboard">Dashboard</a>
<a href="#dataset">Dataset</a>
<a href="#team">Team</a>
</nav>
</header><section class="hero" id="home">
<h2>Student Performance Risk Alert System</h2>
<p>AI-powered platform to identify at-risk students using attendance analysis, performance tracking, smart prediction and academic analytics.</p>
<button class="btn" onclick="showDashboard()">Explore Dashboard</button>
</section><section id="features">
<h2 class="section-title">Features</h2>
<div class="cards">
<div class="card" onclick="openFeature('Performance Analytics Opened 📊')">
<i class="fas fa-chart-line"></i>
<h3>Performance Analytics</h3>
<p>Analyze marks, assignments, attendance and performance trends.</p>
</div><div class="card" onclick="openFeature('Risk Detection Activated ⚠️')">
<i class="fas fa-triangle-exclamation"></i>
<h3>Risk Detection</h3>
<p>Detect academically weak students at an early stage.</p>
</div><div class="card" onclick="openFeature('Reports Generated 📈')">
<i class="fas fa-file-waveform"></i>
<h3>Smart Reports</h3>
<p>Generate visual reports and predictive insights.</p>
</div><div class="card" onclick="openFeature('Notifications Sent 🔔')">
<i class="fas fa-bell"></i>
<h3>Alerts & Notifications</h3>
<p>Send alerts to teachers and students instantly.</p>
</div>
</div>
</section><section id="dashboard">
<h2 class="section-title">Live Dashboard</h2>
<div class="dashboard">
<div class="stats">
<div class="stat-box">
<h2>250</h2>
<p>Total Students</p>
</div><div class="stat-box">
<h2>38</h2>
<p>At Risk Students</p>
</div><div class="stat-box">
<h2>82%</h2>
<p>Average Attendance</p>
</div>
</div><canvas id="myChart"></canvas>

</div>
</section><section id="dataset">
<h2 class="section-title">Upload Dataset</h2>
<div class="upload-box">
<h2>Upload CSV File</h2>
<input type="file" id="fileInput">
<br>
<button class="btn" onclick="analyzeData()">Analyze Dataset</button>
<p id="result"></p>
</div>
</section><section id="team">
<h2 class="section-title">Our Team</h2>
<div class="team">
<div class="member">
<h3>Poorvi</h3>
<p>Frontend & AI Integration</p>
</div><div class="member">
<h3>Team Member 2</h3>
<p>Backend Developer</p>
</div><div class="member">
<h3>Team Member 3</h3>
<p>Data Analyst</p>
</div>
</div>
</section><footer>
<p>© 2026 SPRAS | Hackathon Project</p>
</footer><script>
function openFeature(message){
alert(message);
}

function showDashboard(){
document.getElementById('dashboard').scrollIntoView({behavior:'smooth'});
}

function analyzeData(){
const file=document.getElementById('fileInput').files[0];
if(file){
document.getElementById('result').innerHTML='Dataset Uploaded Successfully ✅';
}
else{
document.getElementById('result').innerHTML='Please Upload a File ❌';
}
}

const ctx=document.getElementById('myChart');
new Chart(ctx,{
type:'bar',
data:{
labels:['Jan','Feb','Mar','Apr','May'],
datasets:[{
label:'Student Performance',
data:[65,59,80,81,56],
backgroundColor:['#1e3c72','#2a5298','#4e73df','#36b9cc','#858796']
}]
},
options:{
responsive:true
}
});
</script></body>
</html>
