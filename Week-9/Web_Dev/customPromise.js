function NewPromise(executorFunction) {
  this.state = "pending";
  this.result = undefined;

  let successCallbacks = [];
  let errorCallbacks = [];

  const resolve = (value) => {
    if (this.state !== "pending") return;

    this.state = "fulfilled";
    this.result = value;

    successCallbacks.forEach((callback) => {
      callback(value);
    });
  };

  const reject = (error) => {
    if (this.state !== "pending") return;

    this.state = "rejected";
    this.result = error;

    errorCallbacks.forEach((callback) => {
      callback(error);
    });
  };

  this.then = function (callback) {
    const newPromise = new NewPromise((resolve, reject) => {
      const successHandler = (value) => {
        try {
          const result = callback(value);
          resolve(result);
        } catch (error) {
          reject(error);
        }
      };

      if (this.state === "fulfilled") {
        successHandler(this.result);
      } else if (this.state === "pending") {
        successCallbacks.push(successHandler);
      }
    });

    return newPromise;
  };

  this.catch = function (callback) {
    const newPromise = new NewPromise((resolve, reject) => {
      const errorHandler = (error) => {
        try {
          const result = callback(error);
          resolve(result);
        } catch (error) {
          reject(error);
        }
      };

      if (this.state === "rejected") {
        errorHandler(this.result);
      } else if (this.state === "pending") {
        errorCallbacks.push(errorHandler);
      }
    });

    return newPromise;
  };

  executorFunction(resolve, reject);
}


new NewPromise((resolve) => {
  resolve(5);
})
.then((value) => {
  return value * 2;
})
.then((value) => {
  return value * 5;
})
.then((value) => {
  console.log(value);
});