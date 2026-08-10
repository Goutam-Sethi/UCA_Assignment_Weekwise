function* calc(initialValue) {
  let result = initialValue;

  while (true) {
    let input = yield result;

    if (
      !input ||
      !["add", "subtract", "multiply", "divide"].includes(input.operation) ||
      typeof input.value !== "number" ||
      isNaN(input.value)
    ) {
      yield "Invalid input";
      continue;
    }

    switch (input.operation) {
      case "add":
        result += input.value;
        break;

      case "subtract":
        result -= input.value;
        break;

      case "multiply":
        result *= input.value;
        break;

      case "divide":
        if (input.value === 0) {
          yield "Cannot divide by zero";
          continue;
        }

        result /= input.value;
        break;
    }
  }
}

let calculator;

function startCalculator() {
  let initialValue = Number(document.getElementById("initialValue").value);

  if (isNaN(initialValue)) {
    document.getElementById("result").innerText = "Invalid initial value";
    return;
  }

  calculator = calc(initialValue);

  let result = calculator.next();

  document.getElementById("result").innerText = result.value;
}

function calculate() {
  if (!calculator) {
    document.getElementById("result").innerText = "Start the calculator first";
    return;
  }

  let operation = document.getElementById("operation").value;

  let value = Number(document.getElementById("value").value);

  let result = calculator.next({
    operation: operation,
    value: value,
  });

  document.getElementById("result").innerText = result.value;
}
