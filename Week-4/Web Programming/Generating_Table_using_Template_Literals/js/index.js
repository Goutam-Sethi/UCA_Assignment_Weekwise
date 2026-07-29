let users = [];

loadUser();
generateTable(users);

function loadUser() {
    setTimeout(() => {
        users = [
            {
                name:"Alice",
                age:53
            },
            {
                name:"Tim",
                age:74
            }
        ];
        generateTable(users);
    }, 2000);
}


function generateTable(users) {
    if (users.length === 0) {
        document.getElementById("appcontent").innerHTML = `
            <h2>Loading users...</h2>
        `;
        return;
    }

    document.getElementById("appcontent").innerHTML = `
        <table>
            <thead>
                <tr>
                    <th>Name</th>
                    <th>Age</th>
                </tr>
            </thead>
            <tbody>
                ${users.map((item) => {
                    return `
                        <tr>
                            <td>${item.name}</td>
                            <td>${item.age}</td>
                        </tr>
                    `;
                }).join("")}
            </tbody>
        </table>
        `;
}
