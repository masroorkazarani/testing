// validateUser.js
import { User } from './login.js';

document.getElementById('loginForm').addEventListener('submit', (event) => {
    event.preventDefault(); // Prevent the form from submitting and refreshing the page

    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;

    const user = new User();
    const result = user.validate(username, password);
    alert(result); // Display the result in an alert box
});
