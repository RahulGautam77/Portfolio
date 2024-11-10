// Smooth Scrolling for Navbar Links
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function (e) {
        e.preventDefault();
        document.querySelector(this.getAttribute('href')).scrollIntoView({
            behavior: 'smooth'
        });
    });
});

// Scroll Reveal Animation for Sections
const sections = document.querySelectorAll('section');

const revealSection = (entries, observer) => {
    const [entry] = entries;

    if (!entry.isIntersecting) return;

    entry.target.classList.add('reveal');
    observer.unobserve(entry.target); // Stop observing once the section is revealed
};

const sectionObserver = new IntersectionObserver(revealSection, {
    root: null,
    threshold: 0.15,
});

sections.forEach(section => {
    sectionObserver.observe(section);
    section.classList.add('hidden'); // Initially hide sections
});

// Form Validation
const form = document.querySelector('form');
const emailInput = form.querySelector('input[type="email"]');
const messageInput = form.querySelector('textarea');

form.addEventListener('submit', function (e) {
    e.preventDefault();

    let valid = true;

    if (!emailInput.value || !validateEmail(emailInput.value)) {
        alert('Please enter a valid email address.');
        valid = false;
    }

    if (!messageInput.value) {
        alert('Please enter a message.');
        valid = false;
    }

    if (valid) {
        alert('Thank you! Your message has been sent.');
        form.reset();
    }
});

// Email Validation Function
function validateEmail(email) {
    const re = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return re.test(String(email).toLowerCase());
}