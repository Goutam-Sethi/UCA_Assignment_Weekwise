function* fibonacci() {
  let a = 0;
  let b = 1;

  while (true) {
    yield a;

    let next = a + b;

    a = b;
    b = next;
  }
}

const fibGen = fibonacci();

const result = document.getElementById("result");

function generateNext() {
  let value = fibGen.next().value;

  let number = document.createElement("span");

  number.className = "number";

  number.innerText = value;

  result.appendChild(number);
}
