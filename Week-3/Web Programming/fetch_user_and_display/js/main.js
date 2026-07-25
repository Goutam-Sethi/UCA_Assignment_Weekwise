const worker = new Worker('js/worker.js');
const usersDiv = document.getElementById('users');

worker.postMessage("start");

worker.onmessage = function(event) {
    const { type, data, message } = event.data;

    if (type === "error") {
        usersDiv.textContent = message;
        return;
    }

    usersDiv.innerHTML = "";

    data.forEach(user => {
        const status = user.id % 2 === 0 ? "Active" : "Inactive";
        const statusClass = user.id % 2 === 0 ? "active" : "inactive";

        const p = document.createElement("p");
        p.innerHTML = `${user.firstName} - <span class="${statusClass}">${status}</span>`;
        usersDiv.appendChild(p);
    });
};

worker.onerror = function() {
    usersDiv.textContent = "No users found";
};