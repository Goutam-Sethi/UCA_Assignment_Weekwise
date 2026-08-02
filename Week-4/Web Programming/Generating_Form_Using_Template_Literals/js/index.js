const fields = [
    "First Name",
    "Last Name",
    "Email"
];

generateForm(fields);

function generateForm(fields) {

    document.getElementById("appcontent").innerHTML = `
        <form>
            <h2>Registration Form</h2>

            ${fields.map((field) => {
                return `
                    <label>${field}</label>
                    <input type="text" placeholder="Enter ${field}">
                `;
            }).join("")}

            <button type="submit">Submit</button>
        </form>
    `;
}