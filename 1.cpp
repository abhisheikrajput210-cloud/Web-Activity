<!DOCTYPE html>
<html lang="en">
  <head><script src="https://cdnjs.cloudflare.com/ajax/libs/jspdf/2.5.1/jspdf.umd.min.js"></script>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Abhishek Billoria | Portfolio</title>
    <link
      rel="stylesheet"
      href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css"
    />
    <style>
      /* CSS Variables */
      :root {
        --primary-color: #2c3e50;
        --secondary-color: #3498db;
        --accent-color: #e74c3c;
        --light-color: #ecf0f1;
        --dark-color: #2c3e50;
        --text-color: #333;
        --text-light: #777;
        --shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
        --transition: all 0.3s ease;
      }

      /* Reset and Base Styles */
      * {
        margin: 0;
        padding: 0;
        box-sizing: border-box;
      }

      html {
        scroll-behavior: smooth;
      }

      body {
        font-family: "Segoe UI", Tahoma, Geneva, Verdana, sans-serif;
        line-height: 1.6;
        color: var(--text-color);
        background-color: var(--light-color);
      }

      a {
        text-decoration: none;
        color: inherit;
      }

      ul {
        list-style: none;
      }

      .container {
        width: 90%;
        max-width: 1200px;
        margin: 0 auto;
        padding: 0 15px;
      }

      .section {
        padding: 80px 0;
      }

      .section-title {
        text-align: center;
        margin-bottom: 50px;
        font-size: 2.5rem;
        color: var(--primary-color);
        position: relative;
      }

      .section-title::after {
        content: "";
        position: absolute;
        bottom: -10px;
        left: 50%;
        transform: translateX(-50%);
        width: 80px;
        height: 4px;
        background-color: var(--secondary-color);
      }

      .btn {
        display: inline-block;
        padding: 12px 30px;
        background-color: var(--secondary-color);
        color: white;
        border: none;
        border-radius: 5px;
        cursor: pointer;
        font-size: 1rem;
        font-weight: 600;
        transition: var(--transition);
      }

      .btn:hover {
        background-color: var(--primary-color);
        transform: translateY(-3px);
        box-shadow: var(--shadow);
      }

      .btn-resume {
        background-color: var(--accent-color);
        display: flex;
        align-items: center;
        gap: 10px;
      }

      .btn-resume:hover {
        background-color: #c0392b;
      }

      /* Header Styles */
      header {
        background-color: var(--primary-color);
        color: white;
        position: fixed;
        width: 100%;
        top: 0;
        z-index: 1000;
        box-shadow: var(--shadow);
      }

      .navbar {
        display: flex;
        justify-content: space-between;
        align-items: center;
        padding: 20px 0;
      }

      .logo {
        font-size: 1.8rem;
        font-weight: 700;
      }

      .logo span {
        color: var(--secondary-color);
      }

      .nav-links {
        display: flex;
      }

      .nav-links li {
        margin-left: 30px;
      }

      .nav-links a {
        font-weight: 500;
        transition: var(--transition);
      }

      .nav-links a:hover {
        color: var(--secondary-color);
      }

      .hamburger {
        display: none;
        cursor: pointer;
      }

      .hamburger span {
        display: block;
        width: 25px;
        height: 3px;
        background-color: white;
        margin: 5px 0;
        transition: var(--transition);
      }

      /* Hero Section */
      .hero {
        height: 100vh;
        background: linear-gradient(rgba(0, 0, 0, 0.7), rgba(0, 0, 0, 0.7)),
          url("https://source.unsplash.com/random/1600x900/?technology")
            no-repeat center center/cover;
        color: white;
        display: flex;
        align-items: center;
        text-align: center;
      }

      .hero-content h1 {
        font-size: 3.5rem;
        margin-bottom: 20px;
      }

      .hero-content p {
        font-size: 1.2rem;
        margin-bottom: 30px;
        max-width: 700px;
        margin-left: auto;
        margin-right: auto;
      }

      .hero-btns {
        display: flex;
        justify-content: center;
        gap: 20px;
        flex-wrap: wrap;
      }

      .btn-outline {
        background-color: transparent;
        border: 2px solid white;
      }

      .btn-outline:hover {
        background-color: white;
        color: var(--primary-color);
      }

      /* About Section */
      .about-content {
        display: grid;
        grid-template-columns: 1fr 2fr;
        gap: 50px;
        align-items: center;
      }

      .about-img {
        border-radius: 10px;
        overflow: hidden;
        box-shadow: var(--shadow);
      }

      .about-img img {
        width: 100%;
        height: auto;
        display: block;
      }

      .about-text h3 {
        font-size: 1.8rem;
        margin-bottom: 20px;
        color: var(--primary-color);
      }

      .about-text p {
        margin-bottom: 20px;
        color: var(--text-light);
      }

      .skills {
        margin-top: 30px;
      }

      .skill-item {
        margin-bottom: 20px;
      }

      .skill-name {
        display: flex;
        justify-content: space-between;
        margin-bottom: 5px;
      }

      .skill-bar {
        height: 10px;
        background-color: #ddd;
        border-radius: 5px;
        overflow: hidden;
      }

      .skill-progress {
        height: 100%;
        background-color: var(--secondary-color);
        border-radius: 5px;
        width: 0;
        transition: width 1.5s ease-in-out;
      }

      /* Projects Section */
      .projects {
        background-color: #f9f9f9;
      }

      .projects-grid {
        display: grid;
        grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
        gap: 30px;
      }

      .project-card {
        background-color: white;
        border-radius: 10px;
        overflow: hidden;
        box-shadow: var(--shadow);
        transition: var(--transition);
      }

      .project-card:hover {
        transform: translateY(-10px);
      }

      .project-img {
        height: 200px;
        overflow: hidden;
      }

      .project-img img {
        width: 100%;
        height: 100%;
        object-fit: cover;
        transition: var(--transition);
      }

      .project-card:hover .project-img img {
        transform: scale(1.1);
      }

      .project-info {
        padding: 20px;
      }

      .project-info h3 {
        margin-bottom: 10px;
        color: var(--primary-color);
      }

      .project-info p {
        color: var(--text-light);
        margin-bottom: 15px;
      }

      .project-tags {
        display: flex;
        flex-wrap: wrap;
        gap: 10px;
        margin-bottom: 15px;
      }

      .project-tag {
        background-color: var(--light-color);
        padding: 5px 10px;
        border-radius: 20px;
        font-size: 0.8rem;
        color: var(--text-light);
      }

      /* Contact Section */
      .contact-content {
        display: grid;
        grid-template-columns: 1fr 1fr;
        gap: 50px;
      }

      .contact-info h3 {
        font-size: 1.5rem;
        margin-bottom: 20px;
        color: var(--primary-color);
      }

      .contact-info p {
        margin-bottom: 20px;
        color: var(--text-light);
      }

      .contact-details {
        margin-top: 30px;
      }

      .contact-item {
        display: flex;
        align-items: center;
        margin-bottom: 15px;
      }

      .contact-icon {
        width: 40px;
        height: 40px;
        background-color: var(--secondary-color);
        color: white;
        border-radius: 50%;
        display: flex;
        align-items: center;
        justify-content: center;
        margin-right: 15px;
      }

      .contact-form {
        background-color: white;
        padding: 30px;
        border-radius: 10px;
        box-shadow: var(--shadow);
      }

      .form-group {
        margin-bottom: 20px;
      }

      .form-group label {
        display: block;
        margin-bottom: 5px;
        font-weight: 500;
      }

      .form-control {
        width: 100%;
        padding: 12px;
        border: 1px solid #ddd;
        border-radius: 5px;
        font-size: 1rem;
        transition: var(--transition);
      }

      .form-control:focus {
        border-color: var(--secondary-color);
        outline: none;
      }

      textarea.form-control {
        min-height: 150px;
        resize: vertical;
      }

      .message {
        padding: 15px;
        margin: 20px 0;
        border-radius: 5px;
        text-align: center;
      }

      .message.success {
        background-color: #d4edda;
        color: #155724;
        border: 1px solid #c3e6cb;
      }

      .message.error {
        background-color: #f8d7da;
        color: #721c24;
        border: 1px solid #f5c6cb;
      }

      /* Footer */
      footer {
        background-color: var(--primary-color);
        color: white;
        padding: 40px 0;
        text-align: center;
      }

      .footer-content {
        display: flex;
        flex-direction: column;
        align-items: center;
      }

      .social-links {
        display: flex;
        gap: 20px;
        margin: 20px 0;
      }

      .social-link {
        width: 40px;
        height: 40px;
        background-color: rgba(255, 255, 255, 0.1);
        border-radius: 50%;
        display: flex;
        align-items: center;
        justify-content: center;
        transition: var(--transition);
      }

      .social-link:hover {
        background-color: var(--secondary-color);
        transform: translateY(-5px);
      }

      .copyright {
        margin-top: 20px;
        color: rgba(255, 255, 255, 0.7);
        font-size: 0.9rem;
      }

      /* Responsive Styles */
      @media (max-width: 992px) {
        .about-content,
        .contact-content {
          grid-template-columns: 1fr;
        }

        .about-img {
          max-width: 400px;
          margin: 0 auto;
        }
      }

      @media (max-width: 768px) {
        .navbar {
          padding: 15px 0;
        }

        .nav-links {
          position: fixed;
          top: 70px;
          left: -100%;
          width: 100%;
          height: calc(100vh - 70px);
          background-color: var(--primary-color);
          flex-direction: column;
          align-items: center;
          justify-content: flex-start;
          padding-top: 50px;
          transition: var(--transition);
        }

        .nav-links.active {
          left: 0;
        }

        .nav-links li {
          margin: 15px 0;
        }

        .hamburger {
          display: block;
        }

        .hamburger.active span:nth-child(1) {
          transform: rotate(-45deg) translate(-5px, 6px);
        }

        .hamburger.active span:nth-child(2) {
          opacity: 0;
        }

        .hamburger.active span:nth-child(3) {
          transform: rotate(45deg) translate(-5px, -6px);
        }

        .hero-content h1 {
          font-size: 2.5rem;
        }

        .hero-btns {
          flex-direction: column;
          align-items: center;
        }

        .btn {
          width: 200px;
          margin-bottom: 10px;
        }
      }

      @media (max-width: 576px) {
        .section-title {
          font-size: 2rem;
        }

        .hero-content h1 {
          font-size: 2rem;
        }

        .projects-grid {
          grid-template-columns: 1fr;
        }
      }
    </style>
  </head>
  <body>
    <!-- Header -->
    <header>
      <div class="container">
        <nav class="navbar">
          <div class="logo">Port<span>folio</span></div>
          <ul class="nav-links">
            <li><a href="#home">Home</a></li>
            <li><a href="#about">About</a></li>
            <li><a href="#projects">Projects</a></li>
            <li><a href="#contact">Contact</a></li>
          </ul>
          <div class="hamburger">
            <span></span>
            <span></span>
            <span></span>
          </div>
        </nav>
      </div>
    </header>

    <!-- Hero Section -->
    <section id="home" class="hero">
      <div class="container">
        <div class="hero-content">
          <h1>Abhishek Billoria</h1>
          <p>Full Stack Developer & UI/UX Designer</p>
          <div class="hero-btns">
            <a href="#projects" class="btn">View My Work</a>
            <a href="#contact" class="btn btn-outline">Contact Me</a>
            <button class="btn btn-resume" id="downloadResume">
              <i class="fas fa-download"></i> Download Resume
            </button>
          </div>
        </div>
      </div>
    </section>

    <!-- About Section -->
    <section id="about" class="section">
      <div class="container">
        <h2 class="section-title">About Me</h2>
        <div class="about-content">
          <div class="about-img">
            <img
              src="https://wallpapercave.com/wp/wp9691900.jpg"
              alt="Abhishek Billoria"
            />
          </div>
          <div class="about-text">
            <h3>Hello! I'm Abhishek Billoria</h3>
            <p>
              I'm a passionate full-stack developer with over 5 years of
              experience creating web applications. I specialize in HTML, CSS,
              JavaScript, PHP, and MySQL, with expertise in modern frameworks
              and libraries.
            </p>
            <p>
              My goal is to create efficient, scalable, and user-friendly
              solutions that solve real-world problems. I enjoy working on
              challenging projects and continuously learning new technologies.
            </p>

            <div class="skills">
              <div class="skill-item">
                <div class="skill-name">
                  <span>HTML/CSS</span>
                  <span>95%</span>
                </div>
                <div class="skill-bar">
                  <div class="skill-progress" data-width="95"></div>
                </div>
              </div>
              <div class="skill-item">
                <div class="skill-name">
                  <span>JavaScript</span>
                  <span>90%</span>
                </div>
                <div class="skill-bar">
                  <div class="skill-progress" data-width="90"></div>
                </div>
              </div>
              <div class="skill-item">
                <div class="skill-name">
                  <span>PHP</span>
                  <span>85%</span>
                </div>
                <div class="skill-bar">
                  <div class="skill-progress" data-width="85"></div>
                </div>
              </div>
              <div class="skill-item">
                <div class="skill-name">
                  <span>MySQL</span>
                  <span>80%</span>
                </div>
                <div class="skill-bar">
                  <div class="skill-progress" data-width="80"></div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </section>

    <!-- Projects Section -->
    <section id="projects" class="section projects">
      <div class="container">
        <h2 class="section-title">My Projects</h2>
        <div class="projects-grid">
          <div class="project-card">
            <div class="project-img">
              <img
                src="https://uicookies.com/wp-content/uploads/2018/03/coloshop-free-bootstrap-ecommerce-website-templates.jpg"
                alt="E-commerce Website"
              />
            </div>
            <div class="project-info">
              <h3>E-commerce Platform</h3>
              <p>
                A full-featured online store with product catalog, shopping
                cart, and payment integration.
              </p>
              <div class="project-tags">
                <span class="project-tag">PHP</span>
                <span class="project-tag">MySQL</span>
                <span class="project-tag">JavaScript</span>
              </div>
              <a href="#" class="btn">View Project</a>
            </div>
          </div>
          <div class="project-card">
            <div class="project-img">
              <img
                src="https://raw.githubusercontent.com/mazipan/bootstrap4-admin-dashboard-template/master/screenshoot.png"
                alt="Admin Dashboard"
              />
            </div>
            <div class="project-info">
              <h3>Admin Dashboard</h3>
              <p>
                Responsive admin panel with data visualization, user management,
                and reporting features.
              </p>
              <div class="project-tags">
                <span class="project-tag">React</span>
                <span class="project-tag">Node.js</span>
                <span class="project-tag">MongoDB</span>
              </div>
              <a href="#" class="btn">View Project</a>
            </div>
          </div>
          <div class="project-card">
            <div class="project-img">
              <img
                src="https://s3-figma-hubfile-images-production.figma.com/hub/file/carousel/img/1a55bdf78e5147e00d8768113b6abf6685c1f010"
                alt="Mobile App"
              />
            </div>
            <div class="project-info">
              <h3>Fitness Tracking App</h3>
              <p>
                Mobile application for tracking workouts, nutrition, and fitness
                progress with social features.
              </p>
              <div class="project-tags">
                <span class="project-tag">React Native</span>
                <span class="project-tag">Firebase</span>
                <span class="project-tag">Redux</span>
              </div>
              <a href="#" class="btn">View Project</a>
            </div>
          </div>
        </div>
      </div>
    </section>

    <!-- Contact Section -->
    <section id="contact" class="section">
      <div class="container">
        <h2 class="section-title">Get In Touch</h2>
        <div class="contact-content">
          <div class="contact-info">
            <h3>Let's Work Together</h3>
            <p>
              I'm always interested in new opportunities and collaborations.
              Whether you have a project in mind or just want to say hello, feel
              free to reach out!
            </p>

            <div class="contact-details">
              <div class="contact-item">
                <div class="contact-icon">
                  <i class="fas fa-envelope"></i>
                </div>
                <div>
                  <h4>Email</h4>
                  <p>abhisheikrajput210@gmail.com</p>
                </div>
              </div>
              <div class="contact-item">
                <div class="contact-icon">
                  <i class="fas fa-phone"></i>
                </div>
                <div>
                  <h4>Phone</h4>
                  <p>+91 8825097182</p>
                </div>
              </div>
              <div class="contact-item">
                <div class="contact-icon">
                  <i class="fas fa-map-marker-alt"></i>
                </div>
                <div>
                  <h4>Location</h4>
                  <p>Jammu & kashmir , IN</p>
                </div>
              </div>
            </div>
          </div>

          <div class="contact-form">
            <div id="formMessage" class="message" style="display: none"></div>

            <form id="contactForm">
              <div class="form-group">
                <label for="name">Name</label>
                <input type="text" id="name" class="form-control" required />
              </div>
              <div class="form-group">
                <label for="email">Email</label>
                <input type="email" id="email" class="form-control" required />
              </div>
              <div class="form-group">
                <label for="subject">Subject</label>
                <input type="text" id="subject" class="form-control" required />
              </div>
              <div class="form-group">
                <label for="message">Message</label>
                <textarea id="message" class="form-control" required></textarea>
              </div>
              <button type="submit" class="btn">Send Message</button>
            </form>
          </div>
        </div>
      </div>
    </section>

    <!-- Footer -->
    <footer>
      <div class="container">
        <div class="footer-content">
          <div class="logo">Port<span>folio</span></div>
          <div class="social-links">
            <a href="#" class="social-link"><i class="fab fa-github"></i></a>
            <a href="#" class="social-link"><i class="fab fa-linkedin"></i></a>
            <a href="#" class="social-link"><i class="fab fa-twitter"></i></a>
            <a href="#" class="social-link"><i class="fab fa-instagram"></i></a>
          </div>
          <p class="copyright">
            &copy; 2025 Abhishek Billoria. All Rights Reserved.
          </p>
        </div>
      </div>
    </footer>

    <!-- JavaScript -->
    <script>
      // Mobile Navigation Toggle
      const hamburger = document.querySelector(".hamburger");
      const navLinks = document.querySelector(".nav-links");

      hamburger.addEventListener("click", () => {
        navLinks.classList.toggle("active");
        hamburger.classList.toggle("active");
      });

      // Close mobile menu when clicking on a link
      document.querySelectorAll(".nav-links a").forEach((link) => {
        link.addEventListener("click", () => {
          navLinks.classList.remove("active");
          hamburger.classList.remove("active");
        });
      });

      // Contact Form Submission
      document
        .getElementById("contactForm")
        .addEventListener("submit", function (e) {
          e.preventDefault();

          // Get form values
          const name = document.getElementById("name").value;
          const email = document.getElementById("email").value;
          const subject = document.getElementById("subject").value;
          const message = document.getElementById("message").value;
          const formMessage = document.getElementById("formMessage");

          // Simple validation
          if (name && email && subject && message) {
            // In a real application, you would send this data to a server
            formMessage.textContent =
              "Thank you for your message! I will get back to you soon.";
            formMessage.className = "message success";
            formMessage.style.display = "block";
            this.reset();

            // Hide message after 5 seconds
            setTimeout(() => {
              formMessage.style.display = "none";
            }, 5000);
          } else {
            formMessage.textContent = "Please fill in all fields.";
            formMessage.className = "message error";
            formMessage.style.display = "block";
          }
        });

      // Smooth scrolling for anchor links
      document.querySelectorAll('a[href^="#"]').forEach((anchor) => {
        anchor.addEventListener("click", function (e) {
          e.preventDefault();

          const targetId = this.getAttribute("href");
          if (targetId === "#") return;

          const targetElement = document.querySelector(targetId);
          if (targetElement) {
            window.scrollTo({
              top: targetElement.offsetTop - 80,
              behavior: "smooth",
            });
          }
        });
      });

      // Add scroll effect to navbar
      window.addEventListener("scroll", function () {
        const header = document.querySelector("header");
        if (window.scrollY > 100) {
          header.style.backgroundColor = "rgba(44, 62, 80, 0.95)";
        } else {
          header.style.backgroundColor = "var(--primary-color)";
        }
      });

      // Animate skill bars when they come into view
      const observerOptions = {
        threshold: 0.5,
      };

      const observer = new IntersectionObserver((entries) => {
        entries.forEach((entry) => {
          if (entry.isIntersecting) {
            const skillBars = entry.target.querySelectorAll(".skill-progress");
            skillBars.forEach((bar) => {
              const width = bar.getAttribute("data-width");
              bar.style.width = width + "%";
            });
          }
        });
      }, observerOptions);

      const skillsSection = document.querySelector(".skills");
      if (skillsSection) {
        observer.observe(skillsSection);
      }

      // Resume Download Functionality with PDF
      document
        .getElementById("downloadResume")
        .addEventListener("click", function () {
          // Create PDF
          const { jsPDF } = window.jspdf;
          const doc = new jsPDF();

          // Add content to PDF
          doc.setFontSize(16);
          doc.text("ABHISHEK BILORIA", 20, 20);
          doc.setFontSize(10);
          doc.text(
            "Kishanpur Ward no-3, Teh- Billawar, Dist- Kathua, Pincode-184204, Jammu and Kashmir",
            20,
            30
          );
          doc.text("Phone: +91 8825097182", 20, 35);

          doc.setFontSize(12);
          doc.text("PROFESSIONAL SUMMARY:", 20, 50);
          doc.setFontSize(10);
          const summary = `
ABHISHEK BILORIA
Kishanpur Ward no-3, Teh- Billawar, Dist- Kathua
Pincode-184204, Jammu and Kashmir
Phone: +91 8825097182
Email: abhisheikrajput210@gmail.com

PROFESSIONAL SUMMARY
Motivated B.Tech Computer Science student with strong foundation in programming and problem-solving. Proficient in C++, Python, Java, and web technologies. Passionate about creating efficient solutions and continuous learning.

TECHNICAL SKILLS

• Programming: C, C++, Python, Java
• Web Development: HTML, CSS, JavaScript
• Database: MySQL
• Other: Data Structures, Algorithms, OOP

EXPERIENCE

Software Intern | TechNova Solutions Pvt. Ltd.
• Developed web-based task management system
• Collaborated in team of 4 on UI components and APIs
• Used Git version control and agile methodologies
• Improved application performance by 20%

EDUCATION

B.Tech Computer Science | Malnad College of Engineering
• Graduation: 2027 | CGPA: 9.2/10
• Coursework: DSA, DBMS, OS, Software Engineering

High School Diploma | Billawar Public School
• Graduated: 2023 | Percentage: 92%
• Stream: Science (Physics, Chemistry, Mathematics)
    `;
          doc.text(summary, 20, 60, { maxWidth: 170 });

          // Continue adding other sections...

          // Save the PDF
          doc.save("Abhishek_Biloria_Resume.pdf");

          // Show download confirmation
          alert("Resume PDF download started!");
        });
    </script>
  </body>
</html>
