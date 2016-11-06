var run = function () {
  var str = new Array(1000000).join('*');
  var doSthWithStr = function () {
  if (str !== 'something')
    console.log("Hi there");
  };
  
  // 由于 doSthWithStr 作为回调函数传给了 setInterval，所以不会被回收
  // 而 str 在它的词法作用域中，并且在函数内部有调用，所以也不会被回收(闭包)
  // 因此内存占用会一直增长
  setInterval(doSthWithStr, 100);
};
setInterval(run, 1000);
