"use client"
import classNames from 'classnames';
import React, { useState, useRef } from 'react';

const Watch: React.FC = () => {
  const [time, setTime] = useState(0);
  const [isRunning, setIsRunning] = useState(false);
  const timerRef = useRef<NodeJS.Timeout | null>(null);

  const startTimer = () => {
    if (!isRunning) {
      setIsRunning(true);
      timerRef.current = setInterval(() => {
        setTime(prevTime => prevTime + 1);
      }, 1000);
    }
  };

  const stopTimer = () => {
    if (isRunning) {
      setIsRunning(false);
      if (timerRef.current) {
        clearInterval(timerRef.current);
        timerRef.current = null;
      }
    }
  };

  const formatTime = (time: number) => {
    const hours = Math.floor(time / 3600);
    const minutes = Math.floor((time % 3600) / 60);
    const seconds = time % 60;
    return `${String(hours).padStart(2, '0')}:${String(minutes).padStart(2, '0')}:${String(seconds).padStart(2, '0')}`;
  };

  return (
    <div>
      <div >{formatTime(time)}</div>
      <button onClick={startTimer} style={{ backgroundColor: 'green', color: 'white', padding: '10px', marginRight: '5px' }}>Start</button>
      <button onClick={stopTimer} style={{ backgroundColor: 'red', color: 'white', padding: '10px' }}>Stop</button>
    </div>
  );
};

export default Watch;
