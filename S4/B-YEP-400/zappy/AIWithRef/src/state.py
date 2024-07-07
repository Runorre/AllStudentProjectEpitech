##
## EPITECH PROJECT, 2024
## zappy
## File description:
## state
##

from __future__ import annotations
from abc import ABC, abstractmethod
from typing import Any


class State(ABC):
    @property
    def context(self) -> Any:
        return self._context

    @context.setter
    def context(self, context: Any) -> None:
        self._context: Any = context

    @abstractmethod
    def handle(self) -> None:
        pass
