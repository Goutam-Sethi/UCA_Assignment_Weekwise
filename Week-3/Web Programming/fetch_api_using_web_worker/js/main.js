const worker = new Worker('js/worker.js');

worker.postMessage("start");

worker.onmessage = function(event) {
    const { type, data, message } = event.data;

    if (type === "error") {
        console.error("Worker error:", message);
        return;
    }

    if (type === "success") {
        data.forEach(user => {
            const status = user.id % 2 === 0 ? "Active" : "Inactive";
            console.log(`${user.firstName} - ${status}`);
        });
    }
};

worker.onerror = function(error) {
    console.error("Worker crashed:", error.message);
};