self.onmessage = async function(event) {
    const command = event.data;

    if (command !== "start") {
        self.postMessage({ type: "error", message: `Unknown command: ${command}` });
        return;
    }

    try {
        const response = await fetch('https://dummyjson.com/users');

        if (!response.ok) {
            throw new Error(`HTTP error: ${response.status}`);
        }

        const data = await response.json();
        const users = data.users;

        if (!users || users.length === 0) {
            self.postMessage({ type: "error", message: "No users found" });
        } else {
            self.postMessage({ type: "success", data: users });
        }
    } catch (err) {
        self.postMessage({ type: "error", message: err.message });
    }
};